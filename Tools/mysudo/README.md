# mysudo
General user to exec cmds with root privileges and without type password (sudo ls  ==> mysudo ls  etc.)

# Compile
```
make

```

# Install
Using *root* privileges to exec cmds as following:
```
chmod 777 mysudo
chown root:root mysudo
mv mysudo /usr/bin/

```

# Examples
*mysudo* could vim /etc/passwd and save the changes.
```
mysudo vim /etc/passwd

```
