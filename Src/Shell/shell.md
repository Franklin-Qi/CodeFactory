# shell script
## 参考
[脚本练习](http://www.freeos.com/guides/lsst/)

## sed命令中使用shell变量
dir=$(pwd)
sed -i " $pwd"  # 此处使用双引号

## 命令行中简化输入
!! 上一条命令
!$ 上一条命令最后一个字符串

$ apt-cache pkgnames |grep man | grep zh
$ sudo apt-get install $(!!)


