#!/bin/bash

i=1
groupadd class1
while [ $i -le 30 ]
do
  # 新增用户名
  if [ $i -le 9 ]
    then
    USERNAME=stu0${i}
  else
    USERNAME=stu${i}
  fi

  # 新增用户
  useradd $USERNAME
  
  mkdir /home/$USERNAME
  chown -R $USERNAME /home/$USERNAME
  chgrp -R class1 /home/$USERNAME
  let i++
done

