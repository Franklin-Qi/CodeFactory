# login-ssh
Local or Remote login through ssh protocol

# Install
Using *root* privileges to exec cmds as follows:
```
mv remote-login.exp /usr/bin/
mv mylogin /usr/bin/

chmod 777 /usr/bin/remote-login.exp
chmod 777 /usr/bin/mylogin
```

# Examples
1. Local login
```
mylogin
```
2. Remote login
```
mylogin root 172.16.1.16 123456
```
remoteName:  root
remoteIP:    172.16.1.16
remotePass:  123456

*remoteName*, *remoteIP*, *remorePass* are three args that you could change personally.
