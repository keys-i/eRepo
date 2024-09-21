# Assignment 2

## Q1. Learn about socket header files and basic system calls.
Socket header files contain data definitions, structures, constants, macros, and options used by
socket subroutines. An application program must include the appropriate header file to make use
of structures or other information a particular socket subroutine requires.
### Commonly used socket header files are:
- `/usr/include/netinet/in.h` Defines Internet constants and structures.
- `/usr/include/netdb.h` Contains data definitions for socket subroutines.
- `/usr/include/sys/socket.h` Contains data definitions and socket structures.
- `/usr/include/sys/types.h` Contains data type definitions.
- `/usr/include/arpa.h` Contains definitions for internet operations.
- `/usr/include/sys/errno.h` Defines the error no values that are returned by drivers and other kernel-level code.
#### Elementary socket system calls:
- `socket()` System Call: Creates an end point for communication and returns a descriptor:<br>
```c
int socket (int AddressFamily, int Type, int Protocol);
```
- `Bind()` System call: Binds a name to a socket. The bind subroutine assigns a Name parameter to an unnamed socket. It assigns a local protocol address to a socket.
```c
int bind (int sockfd, struct sockaddr *myaddr, int addrlen);
```

- `connect()`  System call: The connect function is used by a TCP client to establish a connection with a TCP server.
```c
int connect(int sockfd, struct sockaddr *servaddr, int addrlen);
```

- `listen()` System call: This system call is used by a connection-oriented server to indicate that it is willing to receive connections.
```c
int listen (int sockfd, int backlog);
```
- `accept()` System call: The actual connection from some client process is waited for by having the server execute the accept system call.
```c
int accept (int sockfd, struct sockaddr *cliaddr, int *addrlen);
```

- `send()`, `sendto()`, `recv()` and `recvfrom()` System calls: These system calls are similar to the standard read and write functions.
- `close()` system call: The normal Unix close function is also used to close a socket and terminate a TCP connection.
```c
int close (int sockfd);
```

## Q2. Create an Echo-Server using TCP socket programming in connection- oriented Scenario. Echo Server echo back (return back) the message sent by the client. Also, write the Client side program. While creating program focus on the use of following socket programming functions. `socket()`, sockaddr_in, `bind()`, `listen()`, `accept()`, `ntohs()`, `ntohl()`, `read()`/`recv()`, `write()`/`send()` , `connect()`.

### Steps to be followed:
#### Server Side:
- Include appropriate header files.
- Create a TCP Socket.
- Bind the address and port using bind() system call.
- Server executes listen() system call to indicate its willingness to receive connections.
- Accept the next completed connection from the client process by using an accept() system call. At this point, connection is established between client and server, and they are ready to transfer data.
- Receive a message from the Client using recv()/read() system call.
- Send the received message back(echo) to the client using send()/write() system call.
- Close the socket using close() system call.
#### Client Side:
- Include appropriate header files
- Create a TCP Socket.
- Establish connection to the Server using connect() system call.
- Send and recieve messages using send() and recv() system call respectively.
- Close the socket using close() system call
### Echo Server
  ```c
  /* Copyright 2024 Keys */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>

  #define PORT 12345

  void error(const char *msg) {
      perror(msg);
      exit(1);
  }

  int main(int argc, char *argv[]) {
      int sockfd, newsockfd, portno;
      socklen_t clilen;
      char buffer[256];
      struct sockaddr_in serv_addr, cli_addr;
      int n;

      // Create a TCP socket
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0)
          error("ERROR opening socket");

      // Bind the address and port
      memset((char *) &serv_addr, 0, sizeof(serv_addr));
      portno = PORT;
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_addr.s_addr = INADDR_ANY;
      serv_addr.sin_port = htons(portno);
      if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
          error("ERROR on binding");

      // Listen for incoming connections
      listen(sockfd, 5);
      clilen = sizeof(cli_addr);

      // Accept a connection
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      if (newsockfd < 0)
          error("ERROR on accept");

      // Receive a message from the client
      memset(buffer, 0, 256);
      n = read(newsockfd, buffer, 255);
      if (n < 0) error("ERROR reading from socket");
      printf("Received: %s\n", buffer);

      // Echo the message back to the client
      n = write(newsockfd, buffer, strlen(buffer));
      if (n < 0) error("ERROR writing to socket");

      // Close the socket
      close(newsockfd);
      close(sockfd);
      return 0;
  }
  ```

### Echo Client
  ```c
  /* Copyright 2024 Keys */
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <netdb.h>

  #define PORT 12345

  void error(const char *msg) {
      perror(msg);
      exit(0);
  }

  int main(int argc, char *argv[]) {
      int sockfd, portno, n;
      struct sockaddr_in serv_addr;
      struct hostent *server;

      char buffer[256];
      if (argc < 2) {
          fprintf(stderr,"usage %s hostname\n", argv[0]);
          exit(0);
      }

      // Create a TCP socket
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0)
          error("ERROR opening socket");

      server = gethostbyname(argv[1]);
      if (server == NULL) {
          fprintf(stderr,"ERROR, no such host\n");
          exit(0);
      }

      // Establish connection to the server
      memset((char *) &serv_addr, 0, sizeof(serv_addr));
      portno = PORT;
      serv_addr.sin_family = AF_INET;
      memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      serv_addr.sin_port = htons(portno);
      if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
          error("ERROR connecting");

      // Send a message to the server
      printf("Please enter the message: ");
      memset(buffer, 0, 256);
      fgets(buffer, 255, stdin);
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0)
           error("ERROR writing to socket");

      // Receive the echo back from the server
      memset(buffer, 0, 256);
      n = read(sockfd, buffer, 255);
      if (n < 0)
           error("ERROR reading from socket");
      printf("%s\n", buffer);

      // Close the socket
      close(sockfd);
      return 0;
  }
  ```
