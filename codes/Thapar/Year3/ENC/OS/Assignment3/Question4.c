/* Copyright 2024 Keys */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    close(fd);

    if (unlink("tmpfile.txt") < 0) {
        perror("unlink");
        return 1;
    }

    if (open("tmpfile.txt", O_RDONLY) < 0) perror("File deleted Successfully");
    else printf("File still exists");

    return 0;
}
