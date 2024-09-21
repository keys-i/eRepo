/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
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
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE] = {0};
    ssize_t recv_len;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(PORT);

   // Binding Socket to address and port
   if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))  < 0) {
       perror("Binding Failed");
       exit(EXIT_FAILURE);
   }

   printf("Server is listening on port %d...\n", PORT);

   while(1) {
       recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&client_addr, &addr_len);
       if (recv_len < 0) {
           perror("Failed to receive message");
           exit(EXIT_FAILURE);
       }

       buffer[recv_len] = '\0';

       // Print the recieved message
       printf("Client: %s\n", buffer);

       if (strcmp(buffer, "exit") == 0) {
           printf("Server exiting...\n");
           break;
       }

       reverse_str(buffer);

       // Echo the message back to the client
       if (sendto(sockfd, buffer, recv_len, 0, (struct sockaddr *)&client_addr, addr_len) < 0) {
           perror("Failed to send message");
           close(sockfd);
           exit(EXIT_FAILURE);
       }
   }

   close(sockfd);
   return 0;
}
