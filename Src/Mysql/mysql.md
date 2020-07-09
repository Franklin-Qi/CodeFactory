# MYSQL
Ubunty 下安装MySQL和使用

## 安装MySQL和使用
```
sudo apt install mysql-server mysql-common

# 设置密码复杂度
sudo mysql_secure_installation

# 登录用户和密码查看
sudo vim /etc/mysql/debian.cnf
mysql -udebian-sys-maint -p
```