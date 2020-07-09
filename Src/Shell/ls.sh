#!/bin/bash
comm=$1
loop=$2
echo $loop
i=0
while (( $i < $loop))
do

# ch = $comm是执行命令，并将命令的返回值传给ch变量
# ch=$comm，是将命令本身字符传给ch变量
  ch= $comm
  echo $ch

# 几种方式进行变量自增
# i=$(( $i + 1 ))
 i=$[ $i+1 ]
#  let i++

done
