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

    int fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    write(fd, "Hello, ", 7);
    write(fd_dup, "World!\n", 7);
    close(fd);
    close(fd_dup);
    return 0;
}
