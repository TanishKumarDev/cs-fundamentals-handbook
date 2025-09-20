#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>


int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Setup address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind socket
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    // Start listening
    listen(server_fd, 3);
    std::cout << "Server waiting for connection...\n";

    // Accept a client connection
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    // Read message from client
    read(new_socket, buffer, 1024);
    std::cout << "Client says: " << buffer << std::endl;

    // Send reply
    const char* reply = "Hello from server!";
    send(new_socket, reply, strlen(reply), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to server
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // Send message
    const char* hello = "Hello from client!";
    send(sock, hello, strlen(hello), 0);

    // Receive reply
    read(sock, buffer, 1024);
    std::cout << "Server says: " << buffer << std::endl;

    close(sock);
    return 0;
}