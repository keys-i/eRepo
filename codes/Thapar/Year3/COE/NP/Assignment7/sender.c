/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MULTICAST_GROUP "239.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in multicast_addr;
    char *message = "Hello, Multicast";
    struct ip_mreq mreq;
    int loop = 1;

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socker Creation Failed");
        exit(EXIT_FAILURE);
    }

    memset(&multicast_addr, 0, sizeof(multicast_addr));
    multicast_addr.sin_family = AF_INET;
    multicast_addr.sin_addr.s_addr = inet_addr(MULTICAST_GROUP);
    multicast_addr.sin_port = htons(PORT);

    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop)) < 0) {
        perror("Unable to set socket option");
        close(sock);
        exit(EXIT_FAILURE);
    }

    struct in_addr local_interface;
    local_interface.s_addr = INADDR_ANY;
    if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, &local_interface, sizeof(local_interface)) < 0) {
        perror("Unable to set socket option");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if(sendto(sock, message, strlen(message), 0, (struct sockaddr *)&multicast_addr, sizeof(multicast_addr)) < 0) {
        perror("Send Failed");
        close(sock);
        exit(EXIT_FAILURE);
    } else {
        printf("Message sent to multicast group %s on port %d\n", MULTICAST_GROUP, PORT);
    }

    close(sock);
    return 0;
}
