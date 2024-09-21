# Assignment 2

## Q1. Introduction to the Linux File System and Related Commands

### Linux File System

**Hierarchy**

| Directory | Purpose                                                                                   |
| --------- | ----------------------------------------------------------------------------------------- |
| `/`       | The root directory; the top level of the file system.                                     |
| `/bin`    | Essential command binaries needed for system repair and operation in single-user mode.    |
| `/boot`   | Files related to the bootloader, including the Linux kernel and boot configuration.       |
| `/dev`    | Device files representing hardware components and peripherals.                            |
| `/etc`    | Configuration files for the system and various software packages.                         |
| `/home`   | User's personal directories, where each user has a subdirectory.                          |
| `/lib`    | Essential shared libraries and kernel modules.                                            |
| `/media`  | Mount points for removable media such as USB drives and CDs.                              |
| `/mnt`    | Temporary mount points for file systems.                                                  |
| `/opt`    | Optional application software packages.                                                   |
| `/proc`   | Virtual file system providing process and system information.                             |
| `/root`   | The home directory of the root user.                                                      |
| `/sbin`   | System binaries essential for booting and system repair, typically used by the root user. |
| `/srv`    | Data for services provided by the system, like web servers.                               |
| `/tmp`    | Temporary files used by the system and applications.                                      |
| `/usr`    | Secondary hierarchy for user-related programs and data.                                   |
| `/var`    | Variable data files, such as logs, mail spools, and databases.                            |

### Commands

| **Command**  | **Description**                                                                                                           | **Example**                         |
| ------------ | ------------------------------------------------------------------------------------------------------------------------- | ----------------------------------- |
| **`pwd`**    | Displays the current directory.                                                                                           | `pwd`                               |
| **`ls`**     | Lists files and directories. Options: `-l` for detailed list, `-a` to show hidden files.                                  | `ls`, `ls -la`                      |
| **`cd`**     | Changes the current directory.                                                                                            | `cd /home/username/Documents`       |
| **`mkdir`**  | Creates a new directory.                                                                                                  | `mkdir new_directory`               |
| **`rmdir`**  | Removes an empty directory.                                                                                               | `rmdir new_directory`               |
| **`rm`**     | Deletes files or directories. Option: `-r` to remove directories and their contents recursively.                          | `rm file.txt`, `rm -r directory/`   |
| **`cp`**     | Copies files or directories. Option: `-r` to copy directories recursively.                                                | `cp source.txt destination.txt`     |
| **`mv`**     | Moves or renames files or directories.                                                                                    | `mv old_name.txt new_name.txt`      |
| **`chmod`**  | Changes the permissions of a file or directory. Example: `755` gives the owner full permissions, others can read/execute. | `chmod 755 script.sh`               |
| **`chown`**  | Changes the owner of a file or directory.                                                                                 | `chown username:groupname file.txt` |
| **`df`**     | Displays the amount of disk space available on the file system. Option: `-h` for human-readable format.                   | `df -h`                             |
| **`du`**     | Estimates and displays the disk space used by files and directories. Option: `-h` for human-readable format.              | `du -h /home/username/`             |
| **`mount`**  | Mounts a file system or device to a specified directory.                                                                  | `mount /dev/sda1 /mnt`              |
| **`umount`** | Unmounts a file system or device.                                                                                         | `umount /mnt`                       |
| **`fsck`**   | Checks and repairs a Linux file system. Must be run with `sudo`.                                                          | `sudo fsck /dev/sda1`               |
| **`mkfs`**   | Creates a new file system on a device. Example: `mkfs.ext4` for an ext4 file system.                                      | `mkfs.ext4 /dev/sda1`               |
| **`blkid`**  | Displays information about block devices, including their UUID and file system type.                                      | `blkid /dev/sda1`                   |
| **`ln`**     | Creates a hard or symbolic link to a file. Option: `-s` for symbolic (soft) link.                                         | `ln -s /path/to/file /path/to/link` |

## Q2. Introduction to Vim editor and Shell Scripting basics

### What is Vim?

Vim is a highly configurable text editor that is an improved version of the older vi editor. It's widely used for programming and general text editing, especially on Unix-like systems.

#### Why Use Vim?

- **Efficiency**: Vim is designed for speed and efficiency, allowing you to perform text editing tasks with minimal keystrokes.
- **Modal Editing**: Vim uses different modes for inserting text, navigating, and performing commands, which reduces the need for using the mouse or arrow keys.
- **Customization**: Vim is highly customizable, supporting plugins, scripts, and personalized key mappings.

#### Basic Vim Modes

| Mode        | Purpose                                                                               |
| ----------- | ------------------------------------------------------------------------------------- |
| **Normal**  | The default mode for navigating and manipulating text.                                |
| **Insert**  | Activated by pressing i, a, o, etc., for inserting text.                              |
| **Visual**  | Activated by pressing v, used for selecting text.                                     |
| **Command** | Accessed from Normal Mode by typing : to execute commands like saving, quitting, etc. |

#### Basic Commands

| **Category**            | **Command**        | **Description**                          |
| ----------------------- | ------------------ | ---------------------------------------- |
| **Navigation**          | `h`, `j`, `k`, `l` | Move left, down, up, right respectively. |
|                         | `gg`               | Go to the beginning of the file.         |
|                         | `G`                | Go to the end of the file.               |
| **Editing**             | `i`                | Enter Insert Mode before the cursor.     |
|                         | `x`                | Delete the character under the cursor.   |
|                         | `dd`               | Delete the current line.                 |
|                         | `u`                | Undo the last action.                    |
| **Saving and Quitting** | `:w`               | Save the file.                           |
|                         | `:q`               | Quit Vim.                                |
|                         | `:wq`              | Save and quit.                           |
|                         | `:q!`              | Quit without saving.                     |

### Introduction to Shell Scripting

#### What is a Shell Script?

A shell script is a text file that contains a series of commands for a Unix-based operating system's shell (like Bash) to execute. Shell scripts are used to automate tasks, simplify complex operations, and manage system administration.

#### Why Use Shell Scripting?

- Automation: Repetitive tasks can be automated, saving time and reducing errors.
- System Administration: Shell scripts are widely used for system maintenance, backups, user management, and more.
- Integration: Shell scripts can easily integrate different programs and utilities within a Unix-based system.

#### Basic Shell Script Structure

```bash
#!/bin/bash
# This is a comment
echo "Hello, World!" # This prints Hello, World!
```

> - `#!/bin/bash`: Shebang line indicating the script should be run in the Bash shell.
> - `echo "Hello, World!"`: Command to print text to the terminal.

### Common Commands

#### **Variables:**

```bash
NAME="John"
echo "Hello, $NAME"
```

#### **Conditional Statements:**

```bash
if [ "$NAME" == "John" ]; then
    echo "Welcome, John!"
else
    echo "Who are you?"
fi
```

#### **Loops:**

```bash
for i in 1 2 3; do
    echo "Number $i"
done
```

#### **Functions:**

```bash
my_function() {
    echo "This is a function"
}
my_function
```

### Running a Shell Script

1. **Create a file:** `touch script.sh`
2. **Make it executable:** `chmod +x script.sh`
3. **Run the script:** `./script.sh`

## Q3. Execution of simple C programs using GCC and passing of Command line arguments

```c
// Copyright 2024 Keys
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

```

> To run the above program: <br> > `gcc -o myprogram myprogram.c && ./myprogram hello word 123`

## Q4. Implementation of File System calls:

### (a) Write a program to open an existing file, read its contents, and display them on the console.
```c
// Copyright 2024 Keys
#include <stdio.h>
#include <stdlib.h>

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

    char ch;
    while (ch = fgetc(file) != EOF) {
        putchar(ch);
    }
    return 0;
}

```

### (b) Write a program to copy a file specified by the user at runtime. Use command-line arguments to specify the source and destination file names.

```c
// Copyright 2024 Keys
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

```

### (c) Write a program to create a new file, write a user-specified string into it, and then read the contents of the file and display them.

```c
// Copyright 2024 Keys
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

```

### (d) Write a program to open a file, count the number of words in the file, and display the count.
```c
// Copyright 2024 Keys
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

```

### (e) Write a program to implement a simple file encryption and decryption system. Use simple XOR encryption for the purpose of this assignment.

```c
// Copyright 2024 Keys
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

```
