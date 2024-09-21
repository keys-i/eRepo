# Assignment 4

## Objective: Create a Chat application using TCP socket programming in connection- oriented Scenario.
In Chat application server and client application can chat with each other through text
messages. The chat ends when server or client application sends “exit” message.

### Steps to be followed:
#### Server Side:
- Include appropriate header files.
- Create a TCP Socket.
- Bind the address and port using `bind()` system call.
- Server executes `listen()` system call to indicate its willingness to receive connections.
- Accept the next completed connection from the client process by using an `accept()` system call. At this point, connection is established between client and server, and they are ready to transfer data.
- Receive a message from the Client using `recv()`/`read()` system call.
- Send the received message back(echo) to the client using `send()`/`write()` system call.
- Close the socket using `close()` system call
#### Client Side:
- Include appropriate header files
- Create a TCP Socket.
- Establish connection to the Server using `connect()` system call.
- Send and recieve messages using `send()` and `recv()` system call respectively.
- Close the socket using `close()` system call

### Chat Server
```c
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
```
