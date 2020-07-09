# automake 
一般而言，对于小项目或玩具程序，手动编写 Makefile 即可。但对于大型项目，
手动编写维护 Makefile 成为一件费时费力的无聊工作。一般而言，对于小项目或玩具程序，
手动编写 Makefile 即可。但对于大型项目，手动编写维护 Makefile 成为一件费时费力的无聊工作。

# 自动生成makefile
[linux下使用autoconf制作Makefile](https://www.cnblogs.com/chenshikun/p/6094089.html)
[automake.html](http://www.gnu.org/software/automake/manual/automake.html)
[Autoconf和Automake使用](https://www.cnblogs.com/jeakeven/p/5546614.html)

注：
Makefile.am文件内容：
```
AUTOMARK_OPTIONS=foreign
noinst_PROGRAMS=Hellocsk
Hellocsk_SOURCES=Hellocsk.cpp
```

# automake - 使用 autotools 工具集
[使用 autotools 工具集](https://www.cnblogs.com/gaowengang/p/6170098.html)



