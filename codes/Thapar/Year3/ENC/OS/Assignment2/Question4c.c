/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    char content[256];

    printf("Enter Filename: ");
    scanf("%99s", filename);

    printf("Enter Content: ");
    scanf("%255[^\n]", content);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file.");
        return 1;
    }
    fprintf(file, "%s\n", content);
    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    printf("Contents of %s: \n", filename);
    while (fgets(content, sizeof(content), file)) {
        printf("%s", content);
    }

    fclose(file);
    return 0;
}
