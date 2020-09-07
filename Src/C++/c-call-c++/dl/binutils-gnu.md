# binutils-gnu

## ar生成并查看静态库
> ar rv libNAME.a file1.c file2.c
> ar tv libNAME.a

## 生成动态库文件
> gcc -Wall -shared -fpic -o libNAME.so file1.c file2.c file3.c

## nm 
nm用来列出目标文件中的符号，
可以帮助程序员定位和分析执行程序和目标文件中的符号信息和它的属性。
目前测试动态库可查看，但静态库失败。

> nm -D libNAME.so
或者
> gcc -c main.c -o main.o
> nm main.o

## objcopy
可以将一种格式的目标文件转化为另外一种格式的目标文件。
它使用GNU BFD库进行读/写目标文件。
使用BFD, objcopy就能将原格式的目标文件转化为不同格式的目标文件.

## file
file命令用来判别文件类型

> file test

运行objcopy来改变hello的文件类型: 
原先它是ELF格式的可执行程序, 现将它转换为srec格式.
srec格式文件是Motolora S-Record格式的文件, 主要用来在主机和目标机之间传输数据.

> objcopy -O srec test test_srec
> file test_srec

## objdump 
objdump用来显示目标文件的信息. 可以通过选项控制显示那些特定信息.
objdump一个最大的用处恐怕就是将C代码反汇编了.
在嵌入式软件开发过程中, 也可以用它查看执行文件或库文件的信息.

-f : 显示目标文件的头文件概要信息
> objdump -f test test_srec

生成反汇编代码:
-d : 显示目标文件中机器指令使用的汇编语言.
只反汇编那些应该含有指令机器码的节(显示.text段);
如果用-D, 则反汇编所有节的内容.
> objdump -d main.o

## readelf
readelf用来显示ELF格式目标文件的信息.
可通过参数选项来控制显示哪些特定信息.(注意: readelf不支持显示archive文档).

注意: readelf只能用于ELF格式目标文件, 且选项中至少要指定一个(除V, H外)的选项!

>  readelf -h test

## gprof
gprof被用来测量程序的性能. 它记录每个函数被调用的次数以及相应的执行时间.
这样就能锁定程序执行时花费时间最多的部分, 对程序的优化就可集中于对它们的优化.

```
先将collatz.c编译成目标文件collatz.o， gcc通过 -pg选项来打开gprof支持：
$ gcc -Wall -c -pg collatz.c
$ gcc -Wall -pg -o collatz collatz.o
$ ./collatz
$ gprof ./collatz
```
注意：两条命令都要加 "-pg"选项。前一条命令生成collatz.o目标文件。
后一条命令生成可执行文件，该可执行文件中包含了记录函数执行时间的指令。

生成collatz可执行文件后，现执行它，结果与一般程序的执行无疑。
但此时在PWD目录生成一个名为"gmon.out"的文件，gprof通过它来分析程序的执行。

如果不先执行程序，而直接用gprof来分析它，会提示“gmon.out: No such file or directory”。
