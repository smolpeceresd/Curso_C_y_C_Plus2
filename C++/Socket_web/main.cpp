#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>

using namespace std;

string getHTML(char* hostname_,char *path){
    WSADATA wsaData;
    SOCKET SendingSocket;
    SOCKADDR_IN ServerAddr;
    unsigned int Port = 80;
    int RetCode;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        throw string{"Failed to initialize Winsock\n"};
    }

    // Create a socket
    SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (SendingSocket == INVALID_SOCKET)
    {
        WSACleanup();
        throw string{"Failed to create socket\n"};
    }

    // Get IP address from domain or URL
    const char* hostname = hostname_;  // Replace with the domain or URL
    struct addrinfo hints;
    struct addrinfo* result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0)
    {
        closesocket(SendingSocket);
        WSACleanup();
        throw string{"Failed to get IP address\n"};
    }
    struct sockaddr_in* serverAddr = (struct sockaddr_in*)result->ai_addr;
    char* serverIP = inet_ntoa(serverAddr->sin_addr);

    // Connect to the server
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = inet_addr(serverIP);
    RetCode = connect(SendingSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (RetCode != 0)
    {
        closesocket(SendingSocket);
        WSACleanup();
        freeaddrinfo(result);
        throw string{"Failed to connect to the server\n"};
    }

    // Prepare the HTTP GET request with the hostname
    std::string request = "GET ";
    request += path;
    request += " HTTP/1.1\r\nHost: ";
    request += hostname;
    request += "\r\nConnection: close\r\n\r\n";

    // Send the HTTP GET request to the server
    if (send(SendingSocket, request.c_str(), request.length(), 0) == SOCKET_ERROR)
    {
        closesocket(SendingSocket);
        WSACleanup();
        freeaddrinfo(result);
        throw string{"Failed to send the request\n"};
    }

    // Receive the response from the server and print it
    std::string buffer;
    char tempBuffer[4096];
    int bytesRead;
    while ((bytesRead = recv(SendingSocket, tempBuffer, sizeof(tempBuffer) - 1, 0)) > 0)
    {
        tempBuffer[bytesRead] = '\0';  // Add null-terminator to treat tempBuffer as a string
        buffer += tempBuffer;
    }

    // Close the socket and clean up
    closesocket(SendingSocket);
    WSACleanup();
    freeaddrinfo(result);

    // printf("%s", buffer.c_str());  // Print the content of the buffer as a string

    return buffer;
}

string removeHTMLTags(const std::string& text) {
    // Expresión regular para buscar etiquetas HTML
    std::regex tabulador("\t");
    std::string result = std::regex_replace(text, tabulador, "");
    std::regex espacio("( )+(?=<)");
    result=std::regex_replace(result,espacio,"");
    std::regex etiquetas("<[^>]*>");
    result=std::regex_replace(result,etiquetas,"");

    return result;
}


string getExtraccionInterior(const string &expresion, const string &texto){
    std::regex expresion_(expresion);
    std::string result = std::regex_replace(texto,expresion_, "");
    return result;
}

string getExtraccionExacta(const string &expresion, const string &texto){
    regex hrefPattern("href=\"([^\"]*)\"");
    smatch match;
    if (regex_search(texto, match, hrefPattern)) {
        string hrefValue = match.str(1);
        return hrefValue;
    }
    return "";
}

set<string> getEnlaces(const string &html){

    /**
     * @obtengo todos los <a disponibles
     */
    regex regexPattern("<a[^>]*>.*?<\\/a>");
    smatch match;
    vector<string> aTags;set<string>enlaces;

    string::const_iterator searchStart(html.cbegin());
    while (regex_search(searchStart, html.cend(), match, regexPattern)) {
        string aTag = match.str(0);
        aTags.push_back(aTag);
        searchStart = match.suffix().first;
    }

    /**
     * @De estos debo separar el enlace y el texto
     */
    // Imprimir las etiquetas <a> encontradas
    string href,texto;
    cout << "Etiquetas <a> encontradas:" << endl;
    for (const string& aTag : aTags) {
        href=getExtraccionExacta("href=\"([^\"]*)\"",aTag);
        if(href.at(0)=='/' || href.at(0)=='h'){

            enlaces.insert(href);
        }
        //  texto=getExtraccionInterior("(<([^>]+)>)(.*?)(<//([a-z]+)>)*",aTag);
        // cout<<"\n"<<aTag<<"\nHREF: "<<href<<"\nTexto: "<<texto;
    }
    return enlaces;
}

int main()
{
    int eleccion{0};
    string buffer,hostname="168.83.78.194",path="/";;
    do{
        cout<<"\nhostname: "<<hostname<<" path: "<<path;
        try {
            buffer = getHTML(const_cast<char*>(hostname.c_str()),const_cast<char*>(path.c_str()));

        } catch(string error) {
            cout<<"\nERROR: "<<error;
        }
        int body = buffer.find("<body");
        buffer=buffer.substr(body,(buffer.size()-1)-body);
        set<string> enlaces_= getEnlaces(buffer);
        vector<string> enlaces{enlaces_.begin(),enlaces_.end()};
        buffer = removeHTMLTags(buffer);
        ofstream fichero;fichero.open("HTML.txt",ios::out | ios::trunc);
        fichero<<buffer;
        fichero.close();
        cout<<"\n Se ha creado un fichero HTML para la lectura del HTML.";

        cout<<"\n A donde quieres navegar?";
        for(int i=0; i< enlaces.size();i++){
            /*   if(enlaces.at(i).at(0)=='/'){
                cout<<"\n"<<i<<". http://"<<hostname<<enlaces.at(i);
            }else{

                cout<<"\n"<<i<<". "<<enlaces.at(i);
            }*/
            cout<<"\n"<<i<<". "<<enlaces.at(i);
        }
        cout<<"\n -1 Para salir";
        cout<<"\n IR ";cin>>eleccion;
        if(eleccion!=-1){

            if(enlaces.at(eleccion).at(0)=='/'){
                path=enlaces.at(eleccion);
            }
        }

        system("cls");
    }while (eleccion!=-1);
    cout<<"Finalizado \n\n";
    return 0;
}
