/* Copyright 2024 Keys */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT, O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("This message is written to the file instead of stdout.\n");

    close(fd);
    return 0;
}
