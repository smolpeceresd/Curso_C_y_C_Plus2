#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <ws2tcpip.h>

int main()
{
    WSADATA wsaData;
    SOCKET SendingSocket;
    SOCKADDR_IN ServerAddr;
    unsigned int Port = 80;
    int RetCode;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed to initialize Winsock\n");
        return -1;
    }

    // Create a socket
    SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (SendingSocket == INVALID_SOCKET)
    {
        printf("Failed to create socket\n");
        WSACleanup();
        return -1;
    }

    // Get IP address from domain or URL
    const char* hostname = "nebrija.es";  // Replace with the domain or URL
    struct addrinfo hints;
    struct addrinfo* result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0)
    {
        printf("Failed to get IP address\n");
        closesocket(SendingSocket);
        WSACleanup();
        return -1;
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
        printf("Failed to connect to the server\n");
        closesocket(SendingSocket);
        WSACleanup();
        freeaddrinfo(result);
        return -1;
    }

    // Send an HTTP GET request to the server
    const char* request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    if (send(SendingSocket, request, strlen(request), 0) == SOCKET_ERROR)
    {
        printf("Failed to send the request\n");
        closesocket(SendingSocket);
        WSACleanup();
        freeaddrinfo(result);
        return -1;
    }

    // Receive the response from the server and print it
    char buffer[4096];
    int bytesRead;
    while ((bytesRead = recv(SendingSocket, buffer, sizeof(buffer) - 1, 0)) > 0)
    {
        buffer[bytesRead] = '\0';  // Add null-terminator to treat buffer as a string
        printf("%s", buffer);
    }

    // Close the socket and clean up
    closesocket(SendingSocket);
    WSACleanup();
    freeaddrinfo(result);

    return 0;
}
