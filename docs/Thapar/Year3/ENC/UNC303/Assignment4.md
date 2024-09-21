
# Assignment 4

## Q1. Create and Verify a Directory
Write a program that creates a directory named `test_dir`, changes the current working directory to `test_dir`, and verifies the change.
> **Hint:** Use `mkdir()`, `chdir()`, and `getcwd()` system calls.
```c
/* Copyright 2024 Keys */
#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main() {
    const char *dir_name = "test_dir";
    char cwd[PATH_MAX];

    /* Create Directory */
    if (mkdir(dir_name, 0777) == -1) {
        if (errno == EEXIST) {
            printf("Directory already exists.\n");
        } else {
            perror("mkdir");
            return 1;
        }
    } else {
        printf("Directory %s created successfully.\n", dir_name);
    }

    /* Change to new directory */
    if (chdir(dir_name) == -1) {
        perror("chdir");
        return 1;
    } else {
        printf("Changed to directory %s.\n", dir_name);
    }

    /* Verify the change by print the current working directory */
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }
}
```

## Q2. Remove a Directory and Verify
Write a program that creates a directory named `delete_me`, lists the contents of the current directory, removes the `delete_me` directory, and lists the contents again to verify removal.
> **Hint:** Use `mkdir()`, `rmdir()`, `opendir()`, `readdir()`, and `closedir()` system calls.
```c
```

## Q3. Directory Traversal
Write a program that recursively lists all files and directories starting from the current directory.
> **Hint:** Use a combination of `opendir()`, `readdir()`, and recursion to traverse directories
```c
```
