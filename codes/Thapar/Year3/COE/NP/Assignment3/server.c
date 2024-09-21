/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fill Server information
    memset(&server_addr, 0,  sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Binding failed!");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on %d...\n", PORT);

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        sendto(sockfd, buffer, n, MSG_CONFIRM, (const struct sockaddr *)&client_addr, addr_len);
        printf("Message echoed back to client.\n");
    }

    close(sockfd);
    return 0;
}
