# Top
[Top 经典](https://ycat.top/post/top/)

## Time+
进程所使用的CPU时间，不是进程启动到现在的时间，因此，如果一个进程使用的cpu很少，那即使这个进程已经存在N长时间，TIME/TIME+也是很小的数值。
此外，如果你的系统有多个CPU，或者是多核CPU的话，那么，进程占用多个cpu的时间是累加的。
例如：257:14.655代表的时间是：
从右到左分别是百分之一秒，十分之一秒，秒，十秒，分钟
这个就是257分钟，10秒，4秒，十分之6秒，百分之5秒、千分之5秒，是按位来计算的。