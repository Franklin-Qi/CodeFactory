# 循环
for 循环:
``` Bash
    my_arry=(a b "c","d" abc)
    echo "-------FOR循环遍历输出数组--------"
    for i in ${my_arry[@]}; do
      echo $i
    done

    echo "-------::::WHILE循环输出 使用 let i++ 自增:::::---------"
    j=0
    while [ $j -lt ${#my_arry[@]} ]
    do
      echo ${my_arry[$j]}
      let j++
    done
```

# terminal 命令大集合
[Bash 终端命令大集合](https://segmentfault.com/a/1190000020901442)
[Github bash 命令](https://github.com/onceupon/Bash-OneLiner#math)

[bash 高效](https://segmentfault.com/a/1190000002760973)
Esc + u  将文本从光标的开始到结尾的单词转换为大写
Esc + l  将文本从光标的开始到结尾的单词转换为小写
Esc + c  将光标下的字母转换为大写
Ctrl + ]　c ：从当前光标处向右定位到字符 c 处
Esc　Ctrl + ]　c ：从当前光标向左定位到字符 c 处。（ bind -P 可以看到绑定信息）
