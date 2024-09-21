/* Copyright 2024 Keys */
#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MULTICAST_GROUP "239.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in recv_addr;
    struct ip_mreq mreq;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socker Creation Failed");
        exit(EXIT_FAILURE);
    }

    int reuse = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(sock)) < 0) {
        perror("Unable to set socket option");
        close(sock);
        exit(EXIT_FAILURE);
    }

    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = INADDR_ANY;
    recv_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&recv_addr, sizeof(recv_addr)) < 0) {
        perror("Bind Failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    mreq.imr_multiaddr.s_addr = inet_addr(MULTICAST_GROUP);
    mreq.imr_interface.s_addr = INADDR_ANY;
    if(setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0){
        perror("Unable to set socket option");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Receiver is listening on port 12345...\n");

    addr_len = sizeof(recv_addr);
    ssize_t recv_len = recvfrom(sock ,buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&recv_addr, &addr_len);
    if (recv_len < 0) {
        perror("Receive Failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    buffer[recv_len] = '\0';
    printf("Received: %s\n", buffer);

    close(sock);
    return 0;
}
