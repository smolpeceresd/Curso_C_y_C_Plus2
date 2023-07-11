#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Inicializar Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error al inicializar Winsock" << std::endl;
        return 1;
    }

    // Crear un socket TCP
    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Error al crear el socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // Obtener la dirección IP del servidor a partir de la URL
    std::string url = "nebrija.es";  // Reemplaza con tu URL
    struct addrinfo* result = nullptr;
    struct addrinfo hints{};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(url.c_str(), "80", &hints, &result) != 0) {
        std::cerr << "No se pudo obtener la dirección IP del servidor" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }
    struct sockaddr_in serverAddress{};
    memcpy(&serverAddress, result->ai_addr, result->ai_addrlen);
    freeaddrinfo(result);

    // Conectar con el servidor
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Error al conectarse al servidor" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Enviar una solicitud HTTP GET para obtener el HTML
    std::string request = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";
    if (send(sockfd, request.c_str(), request.length(), 0) == SOCKET_ERROR) {
        std::cerr << "Error al enviar la solicitud HTTP" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Recibir y mostrar la respuesta del servidor
    const int bufferSize = 4096;
    char buffer[bufferSize];
    std::string response;
    while (true) {
        int bytesRead = recv(sockfd, buffer, bufferSize - 1, 0);
        if (bytesRead == SOCKET_ERROR || bytesRead == 0) {
            break;  // Fin de la respuesta o error
        }
        buffer[bytesRead] = '\0';
        response += buffer;
    }

    std::cout << "Respuesta del servidor:\n" << response << std::endl;

    // Cerrar el socket y limpiar Winsock
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
