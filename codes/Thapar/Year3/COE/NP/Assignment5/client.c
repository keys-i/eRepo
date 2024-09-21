/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    size_t recv_len;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Creation Failed.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    while(1) {
        printf("Enter a message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // Send message to server
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len) < 0) {
            perror("Send failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        // Check for exit condition
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Receive response from server
        recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&server_addr, &addr_len);
        if (recv_len < 0) {
            perror("Receive failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        buffer[recv_len] = '\0'; // Null-terminate the received string
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
