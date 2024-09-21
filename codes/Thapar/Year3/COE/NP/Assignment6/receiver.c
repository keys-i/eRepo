/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in recv_addr, cli_addr;
    socklen_t cli_addr_len;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the receiver address
    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(12345);
    recv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(sock, (struct sockaddr*)&recv_addr, sizeof(recv_addr)) < 0) {
        perror("Binding failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Receiver is listening on port 12345...\n");

    // Receive data
    cli_addr_len = sizeof(cli_addr);
    ssize_t recv_len = recvfrom(sock, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cli_addr, &cli_addr_len);
    if (recv_len < 0) {
        perror("Failed to receive message");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Null-terminate and print the received message
    buffer[recv_len] = '\n';
    printf("Received Message: %s\n", buffer);

    // Close the socket
    close(sock);
    return 0;
}
