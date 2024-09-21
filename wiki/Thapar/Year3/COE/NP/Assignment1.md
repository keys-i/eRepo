# Assignment 1

## Learn to configure telnet, ftp, and SSH server on Unix platforms.
 a) Install and configure FTP Server on Ubuntu with vsftpd.<br>
 b) Install and configure Telent Server on Ubuntu with telnetd.<br>
 c) Install and configure SSH Server on Ubuntu with OpenSSH.

The step by step procedure for installation and configuration of FTP, Telnet and SSH is provided
for your help.

### a) Install and configure FTP Server on Ubuntu with vsftpd.
1. Update package index and Install FTP.
```bash
sudo apt update && sudo apt install vsftpd
```

2. Configure the FTP server
```bash
sudo nano /etc/vsftpd.conf
```

3. Add the following configurations to the `vsftpd.conf` file.
  ```conf
  listen=YES                    # allows listening
  listen_ipv6=NO                # disable listening for IPv6
  anonymous_enable=NO           # disable anonymous access
  local_enable=YES              # enable local user access
  write_enable=YES              # enable the FTP to be editable

  # Optional Configurations
  chroot_local_user=YES         # confines users to their home directory
  allow_writeable_chroot=YES    # allows home directory for each user to editable
  ```

4. Restart the vsftpd service.
```bash
sudo systemctl restart vsftpd
```

5. Allow FTP though Firewall.
```bash
sudo ufw allow 21/tcp
sudo ufw reload
```

6. Test the FTP server.
```bash
ftp localhost
```

### b) Install and configure Telent Server on Ubuntu with telnetd.
1. Update package index and Install Telnet.
```bash
sudo apt update && sudo apt install telnetd
```

2. Configure Telnet Server.
```bash
sudo systemctl enable telnet.service
sudo systemctl start telnet.service
```

3. Allow Telnet though Firewall.
```bash
sudo ufw allow 23/tcp
sudo ufw reload
```

4. Test the server
```bash
telnet localhost
```

### c) Install and Configure SSH Server with OpenSSH
1. Update package index and Install OpenSSH.
```bash
sudo apt update && sudo apt install openssh-server
```

2. Configure OpenSSH server
```bash
sudo nano /etc/ssh/sshd_config
```

4. Uncomment the following lines
```conf
Port 22                   # port for SSH
PermitRootLogin no        # disable root login over SSH
PasswordAuthentication    # allow password Authentication
```

5. Restart the SSH service.
```bash
sudo systemctl restart ssh
```

6. Allow SSH through Firewall.
```bash
sudo ufw allow 22/tcp
sudo ufw reload
```

7. Test the SSH server.
```bash
ssh username@localhost
```
