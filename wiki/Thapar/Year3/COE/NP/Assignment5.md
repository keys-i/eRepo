# Assignment 5

## Objective: Implement Chat application between server and client using UDP socket programming in a connection-less scenario.
In Chat application server and client application can chat with each other through text messages.
The chat ends when server or client application sends “exit” message.

### Steps:
#### Server Side:
- Include appropriate header files.
- Create a UDP Socket.
- Create an address by using server’s IP address and server port with sockaddr_in().
- Bind the address and port using bind() system call.
- Receive a message from the Client using recvfrom() system call.
- Send the received message back(echo) to the client using sendto() system call.
- Close the socket using close() system call

#### Client Side:
- Include appropriate header files
- Create a UDP Socket.
- Create an address by using server’s IP address and server port with sockaddr_in().
- Send and receive messages using sendto() and recvfrom() system call respectively.
- Close the socket using close() system call

### Chat Server
```c
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
```

### Chat Client
```c
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
```
