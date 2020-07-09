# 使用rsyslog记录日志
通过自定义增加的环境变量进行开启日志开关进行调试。

## rsyslog配置文件rsyslog.conf修改
```
#Mylog
local2.* /var/log/mylog
```

``` 环境变量通过export增加进行调试
环境变量命名规则：软件名_DEBUG_作者名

export MUTTER_DEBUG_YUSQ="1" // 增加或更改环境变量, 调试前, 设置后可以进行运行软件查看日志

unset  MUTTER_DEBUG_YUSQ     // 删除环境变量, 调试后


```

修改完保存后重启rsyslog服务     :/etc/init.d/rsyslog restart    或service rsyslog restart  或systemctl restart rsyslog

## 测试代码
log.c

增加环境变量: export MYDEBUG=1
gcc a.c 编译执行后，在/var/log/mylog中多了一行记录



# debug
日志记录syslog不生效
[rsyslog没有记录](https://codeday.me/bug/20190808/1626079.html)

rm -f /var/lib/rsyslog/imjournal.state
systemctl restart rsyslog
