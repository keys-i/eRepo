/* Copyright 2024 Keys */
#include <asm-generic/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;
    int broadcast = 1;
    char *message = "Hello, Broadcast";

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0 ) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("Failed to set socket option");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.1.255");
    server.sin_port = htons(12345);

    if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to send message");
        close(sock);
        exit(EXIT_FAILURE);
    }

    close(sock);
    return 0;
}
