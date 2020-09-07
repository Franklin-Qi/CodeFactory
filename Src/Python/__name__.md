# 经常看见的__name__和"__main__"
> `system-config-services`源码src/gui.py模块文件中在底部代码中看到__name__
> 与"__main__"，那么它们代表什么呢?

## __name__
__name__ 是当前模块的一个属性，它是一个内置属性，也称内置变量。


## __main__
"__main__"是一个字符串对象。

## __name__和"__main__"联系
```
if __name__=="__main__":
    if "--no-dbus" in sys.argv[1:]:
        use_dbus = False
    elif "--dbus" in sys.argv[1:]:
        use_dbus = True
    else:
        use_dbus = None

1. 当前模块作为程序入口执行时为true；
2. 当前模块import到其他模块时为false。此时if代码中代码不执行。

也就是，此行代码可以调用一些测试代码。 

sys.argv[1:] 代表者取命令行列表第一个元素后的值，也就是所有参数。
```
