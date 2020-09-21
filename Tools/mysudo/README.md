# mysudo
General user to exec cmds with root privileges and without type password (sudo ls  ==> mysudo ls  etc.)

# Compile
```
make

```

# Install
Using *root* privileges to exec cmds as following:
```
sudo cp mysudo /usr/sbin
sudo chown root:root /usr/sbin/mysudo
sudo chmod 4777 /usr/sbin/mysudo

```
or just do this:
```
sudo bash install.sh
```

# Examples
*mysudo* could vim /etc/passwd and save the changes.
```
mysudo vim /etc/passwd

```
