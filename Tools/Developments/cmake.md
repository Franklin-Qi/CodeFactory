# cmake 
doxygen 源码编译需要3.2上，而兆芯koji上是3.0，所以升级。
cmake --version  查看版本

## Install
```
wget https://cmake.org/files/v3.5/cmake-3.5.2.tar.gz
tar xvf cmake-3.5.2.tar.gz
cd cmake-3.5.2
./bootstrap --prefix=/usr/ 或者 /usr/local 否则不会自动找到: env | grep PATH ==> /usr/: /usr/local
make && make install

```

./bootstrap --prefix=/usr/share
安装如上进行操作，camke --version 版本还是3.0, 并未升级。进行如下操作：
1. mv /usr/bin/cmake  ~/   备份3.0 版本到root的  ~/
2. ln -s /usr/share/cmake/completions/cmake /usr/bin/cmake 指定/usr/bin环境下为3.5 版本





