## 通过env环境变量控制日志开关
env.md 
rsyslog.md
log.c  // 在每个函数调用之前和之后打印日志

## 调试printf
```
#define __DEBUG__  
#ifdef __DEBUG__  
#define DEBUG(format,...) \
    printf("File: "__FILE__", Line: %05d: "format"/n", __LINE__, ##__VA_ARGS__)  
#else  
#define DEBUG(format,...)  
#endif


在每个函数调用之前和之后打印日志
https://bbs.csdn.net/topics/290055674
http://www.codes51.com/itwd/3905862.html


函数体中开始增加对应消息，同时要区分开函数头和调用函数的地方。
```

## 处理aarch问题
一般情况下，软件都应该装在/usr/share/下, 利用Ctrl+Alt+F[1-9] 进行切换命令行和图形界面，
startx进入图形界面复现问题。

1. 可以先在兆芯本地上，进行grep -nr "LockScreen" /usr/share/ , 其中LockScreen是在英文界面下显示字符串;
2. rpm -qf 查找rpm包;
3. 查看koji版本，如果旧的有问题，那么yum update 指定包进行查看问题是否复现；
4. 合并新版本

rpmbuild -bp aarch平台时，可以加上--target=aarch
/home/yusq/rpmbuild/SRPMS/mate-session-manager-1.16.1-3.nd7.13.src.rpm

