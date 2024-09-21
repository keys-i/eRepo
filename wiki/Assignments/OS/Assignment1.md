# Assignment 1

## Q1. Introduction to Various Linux Operating Systems and Basic Commands
### Various Linux Distributions
Linux is an open-source operating system that is widely used for a variety of purposes, including servers, desktops, and embedded systems. It is known for its stability, security, and flexibility. Here are some popular Linux distributions:

| **Distribution** | **Use Case**                        | **Description**                                                                                                                                           |
|------------------|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Ubuntu**       | Desktop, server, and cloud computing | Ubuntu is one of the most popular Linux distributions, especially for beginners. It is user-friendly and has a large community for support.               |
| **Fedora**       | Desktop, development, and servers   | Fedora is a cutting-edge Linux distribution that offers the latest software and features. It is the upstream source for Red Hat Enterprise Linux (RHEL).   |
| **Debian**       | Server, desktop, and embedded       | Debian is a highly stable and reliable distribution. It is the foundation for many others, including Ubuntu. Debian focuses on free software and quality.  |
| **CentOS**       | Server environments                 | CentOS was compatible with Red Hat Enterprise Linux (RHEL) and widely used in enterprise environments for stability and security. Now CentOS Stream.      |
| **Arch Linux**   | Advanced users, customization       | Arch Linux is a lightweight and flexible distribution that follows a rolling-release model. It is highly customizable and suited for experienced users.    |
| **AlmaLinux**    | Server environments                 | AlmaLinux is a community-driven replacement for CentOS, aiming to be a stable, production-grade operating system.                                           |
| **Kali Linux**   | Security testing                    | Kali Linux is a Debian-based distribution designed for digital forensics and penetration testing, with numerous pre-installed security auditing tools.     |

### Basic Linux Commands
| **Command**     | **Description**                                                                                                           | **Example**                        |
|-----------------|---------------------------------------------------------------------------------------------------------------------------|------------------------------------|
| **`pwd`**       | Displays the current directory.                                                                                           | `pwd`                              |
| **`ls`**        | Lists files and directories. Options: `-l` for detailed list, `-a` to show hidden files.                                  | `ls`, `ls -la`                     |
| **`cd`**        | Changes the current directory.                                                                                            | `cd /home/username/Documents`      |
| **`mkdir`**     | Creates a new directory.                                                                                                  | `mkdir new_directory`              |
| **`rmdir`**     | Removes an empty directory.                                                                                               | `rmdir new_directory`              |
| **`rm`**        | Deletes files or directories. Option: `-r` to remove directories and their contents recursively.                          | `rm file.txt`, `rm -r directory/`  |
| **`cp`**        | Copies files or directories. Option: `-r` to copy directories recursively.                                                | `cp source.txt destination.txt`    |
| **`mv`**        | Moves or renames files or directories.                                                                                    | `mv old_name.txt new_name.txt`     |
| **`cat`**       | Displays the contents of a file.                                                                                          | `cat file.txt`                     |
| **`nano`/`vim`**| Edits files directly from the command line.                                                                               | `nano file.txt`, `vim file.txt`    |
| **`chmod`**     | Changes the permissions of a file or directory. Example: `755` gives the owner full permissions, others can read/execute. | `chmod 755 script.sh`              |
| **`chown`**     | Changes the owner of a file or directory.                                                                                 | `chown username:groupname file.txt`|
| **`df`**        | Displays the amount of disk space available on the file system. Option: `-h` for human-readable format.                   | `df -h`                            |
| **`du`**        | Estimates and displays the disk space used by files and directories. Option: `-h` for human-readable format.              | `du -h /home/username/`            |
| **`mount`**     | Mounts a file system or device to a specified directory.                                                                  | `mount /dev/sda1 /mnt`             |
| **`umount`**    | Unmounts a file system or device.                                                                                         | `umount /mnt`                      |
| **`fsck`**      | Checks and repairs a Linux file system. Must be run with `sudo`.                                                          | `sudo fsck /dev/sda1`              |
| **`mkfs`**      | Creates a new file system on a device. Example: `mkfs.ext4` for an ext4 file system.                                      | `mkfs.ext4 /dev/sda1`              |
| **`blkid`**     | Displays information about block devices, including their UUID and file system type.                                      | `blkid /dev/sda1`                  |
| **`ln`**        | Creates a hard or symbolic link to a file. Option: `-s` for symbolic (soft) link.                                         | `ln -s /path/to/file /path/to/link`|
| **`top`**       | Displays real-time information about running processes.                                                                   | `top`                              |
| **`ps`**        | Displays information about active processes.                                                                              | `ps aux`                           |
| **`kill`**      | Terminates a process by its PID (Process ID).                                                                             | `kill 1234`                        |
| **`grep`**      | Searches for specific text patterns in files.                                                                             | `grep "pattern" file.txt`          |
| **`find`**      | Searches for files and directories based on criteria.                                                                     | `find /home -name "file.txt"`      |
| **`tar`**       | Archives files into a tarball or extracts them. Option: `-xvf` to extract files from an archive.                          | `tar -cvf archive.tar directory/`  |
| **`sudo`**      | Executes a command with superuser (root) privileges.                                                                      | `sudo apt-get update`              |
