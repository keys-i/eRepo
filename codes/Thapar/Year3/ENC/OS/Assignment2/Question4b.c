/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("Error opening source file.");
        return 1;
    }

    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("Error opening destination file.");
        fclose(source);
        return 1;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, sizeof(buffer), destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}
