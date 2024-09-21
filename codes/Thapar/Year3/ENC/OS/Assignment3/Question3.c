/* Copyright 2024 Keys */
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
