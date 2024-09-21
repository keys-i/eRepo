# Assignment 3

## Q1. File Descriptor Duplication Using `dup()`
Write a program that opens a file, duplicates its file descriptor using `dup()`, writes to both the original and duplicated file descriptors, and then verifies the contents of the file.
> **Hint:** Use `open()`, `dup()`, `write()`, and `close()` system calls.
```c
// Copyright 2024 Keys
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
``````c
// Copyright 2024 Keys
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

``````c
// Copyright 2024 Keys
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main() {
    if (link("orignal.txt", "hardlink.txt") < 0) {
        perror("link");
        return 1;
    }

    struct stat statbuf;
    if (stat("orignal.txt", &statbuf) == 0)
        printf("Orignal file: inode: %lu\n", statbuf.st_ino);

    if (stat("hardlink.txt", &statbuf) == 0)
        printf("Hard Link inode: %lu\n", statbuf.st_ino);
    return 0;
}

``````c
// Copyright 2024 Keys
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
```