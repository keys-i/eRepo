/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    int c, prev = ' ', word_count = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c) && !isspace(prev)) {
            word_count++;
        }
        prev = c;
    }
    if (!isspace(prev)) {
        word_count++;
    }
    fclose(file);
    printf("Number of words in %s: %d\n", argv[1], word_count);
    return 0;
}
