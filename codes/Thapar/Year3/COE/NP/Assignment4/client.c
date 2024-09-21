#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    //
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);\

    // Convert IP Addreesses to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Connection Failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while(1) {
        printf("You: ");

        fgets(buffer, BUFFER_SIZE, stdin);

        // Send a message to the server
        send(sock, buffer, strlen(buffer), 0);

        if(strncmp(buffer, "exit", 4) == 0) {
            printf("Client exiting...\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        // Recieve the message from the server
        int read_bytes = recv(sock, buffer, BUFFER_SIZE, 0);
        if (read_bytes <= 0) {
            printf("Server disconnected.\n");
            break;
        }

        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}
