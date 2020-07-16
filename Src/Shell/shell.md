# shell script
## 参考
[脚本练习](http://www.freeos.com/guides/lsst/)

## shell 配置文件
> /etc/shells

## sed命令中使用shell变量
dir=$(pwd)
sed -i " ${pwd}"  # 此处使用双引号

## 命令行中简化输入
!! 上一条命令
!$ 上一条命令最后一个字符串

$ apt-cache pkgnames |grep man | grep zh
$ sudo apt-get install $(!!)

## 执行命令结果输出到文件
```
1. 覆盖写入：
echo "xxx"  > 文件

2. 追加写入：
echo "xxx"    >> 文件

3. linux shell中"2>&1"含义
对于& 1 更准确的说应该是文件描述符 1,而1标识标准输出，stdout。
对于2 ，表示标准错误，stderr。
2>&1 的意思就是将标准错误重定向到标准输出。
index.php task testOne >/dev/null 2>&1 （忽略所有的输出）
```
