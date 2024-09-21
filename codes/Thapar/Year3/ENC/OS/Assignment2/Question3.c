/* Copyright 2024 Keys */
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No arguments provided.\n");
        return 1;
    }

    printf("Number of arguments: %d\n", argc);
    printf("Arguments passed:\n");

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
