#!/bin/bash

i=1
while [ $i -le 10 ]
do
  if [ $i -le 9 ];then
    USERNAME=ysq0$i
  else
    USERNAME=ysq${i}
  fi

  # userdel 用户
  userdel -r $USERNAME
#  i=$[ $i + 1 ]
  i=`expr $i + 1`
done




