/* Copyright 2024 Keys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor_encrypt(FILE *input, FILE *output, char *key) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ *key, output);
    }
}

void xor_decrypt(FILE *input, FILE *output, char *key) {
    xor_encrypt(input, output, key);  // XOR is symmetric, so encryption and decryption
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <mode> <filename> <key>\n", argv[0]);
        fprintf(stderr, "Modes: encrypt or decrypt\n");
        return 1;
    }

    const char *mode = argv[1];
    const char *filename = argv[2];
    char *key = argv[3];

    FILE *input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char output_filename[256];
    if (strcmp(mode, "encrypt") == 0) {
        snprintf(output_filename, sizeof(output_filename), "%s.enc", filename);
    } else if (strcmp(mode, "decrypt") == 0) {
        snprintf(output_filename, sizeof(output_filename), "%s.dec", filename);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        fclose(input_file);
        return 1;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    if (strcmp(mode, "encrypt") == 0) {
        xor_encrypt(input_file, output_file, key);
    } else {
        xor_decrypt(input_file, output_file, key);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Operation %s completed successfully, Output file: %s\n", mode, output_filename);

    return 0;
}
