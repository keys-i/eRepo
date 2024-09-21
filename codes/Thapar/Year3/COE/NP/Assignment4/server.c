/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void reverse_str(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client Connected.\n");

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_bytes = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (read_bytes <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        buffer[strcspn(buffer, "\r\n")] = 0;

        printf("Client: %s\n", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Server exiting...\n");
            break;
        }

        reverse_str(buffer);

        send(new_socket, buffer, strlen(buffer), 0);

        printf("Server: %s\n", buffer);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
