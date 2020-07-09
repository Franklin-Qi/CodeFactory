# github
[![Build Status](https://travis-ci.org/mate-desktop/caja.svg?branch=master)](https://travis-ci.org/mate-desktop/caja)
[![Release](https://img.shields.io/github/v/release/mate-desktop/caja)](https://github.com/mate-desktop/caja/releases)
[![IRC Network](https://img.shields.io/badge/irc-freenode-blue.svg "IRC Freenode")](https://webchat.freenode.net/?channels=mate)
![AppVeyor](https://img.shields.io/appveyor/build/yusq77/kylin-scanner?style=plastic)

## 取消git init操作
> rm -rf .git

## Git命令行首次提交项目
1. 在网页上进行新建一个远程项目，并拷贝地址
2. 进入本地项目根目录，git init 进行初始化仓库
3. git add . //把目录下的文件全部提交到本地缓冲区
4. git commit -m ”first commit" //提交到本地并添加说明
5. git remote add origin https://git.oschina.net/xxx/xxx.git（第一步中copy下来的地址） //提交项目

6. git pull origin
   git pull --rebase origin master //本地与远程代码合并

7. git push --set-upstream origin master  //最后提交到远程仓库


1. 初步配置:
```bash
git config --global user.name shuoqi.yu
git config --global user.email shuoqi.yu@cs2c.com.cn


git config --global user.name shuoqi.yu
git config --global user.email yushuoqi@kylinos.cn
```

## fork他人项目后，再同步更新别人的提交。
```
# 查看远程信息
git remote -v

# 添加远程仓库xxx(upstream为仓库别名)
git remote add upstream https://github.com/mahailiang/kylin-scanner.git

# 删除远程仓库，可不使用
git remote remove upstream

# 查看远程信息
git remote -v


第一种情况，个人仓库和主仓库没同步，个人仓库没更改，主仓库更改，直接同步主仓库:

git fetch upstream # 从源仓库更新同步代码，必须

git merge upstream/master # 合并到本地代码，必须
{
git合并的时候，冲突问题Merging is not possible because you have unmerged files

你手动修改git提示有错误的文件，修改之后，添加有冲突的文件： git add [被修改的冲突文件]， 最后，按照普通提交那样，提交有冲突的问题： git commit [修改后的冲突文件] -m “注释内容”

*简单的来说就是：
用git diff或者git status 查看哪些文件冲突，有冲突的会提示：
++<<<<<<< HEAD

# 这部分是自己仓库的

===========

# 这部分是上游仓库的

++<<<<<<< upstream

修改你的冲突的文件，修改完之后，保存。
用git add xxx，把你修改的文件全部都添加进去。
最后，用git commit -a -m ” 备注信息 ” 提交，完成。

}

git commit -m "upstream sync" # 提交远程仓库的数据
git pull origin master # 更新并合并自己远程仓库的代码
git push # 向自己的远程仓库同步刚才源仓库后的代码




第二种情况，个人仓库和主仓库已同步，提交个人代码到个人仓库中，同时做一些验证:

# simply github operations, git add/commit/status/log ...
git fetch upstream # 从源仓库更新同步代码，必须
git merge upstream/master # 合并到本地代码，必须
git pull origin master # 更新并合并自己远程仓库的代码
git push # 向自己的远程仓库同步刚才源仓库后的代码

```
https://blog.csdn.net/qq1332479771/article/details/56087333

## 下载单个/部分文件
1. 下载单个文件，可以Raw右键链接另存为或者复制链接
2. 下载部分文件夹，Chrome扩展插件 **GitZip for github**，*failed*.
3. 下载部分文件夹，下载TortoiseSVN
```
1. master分支, 将 /tree/master/ 换成 /trunk/;
2. 不是master分支(如dev分支), /trunk/ => /branches/dev/
```

## git clone速度太慢
原因：git clone特别慢是因为github.global.ssl.fastly.net域名被限制了。只要找到这个域名对应的ip地址，然后在hosts文件中加上ip–>域名的映射，刷新DNS缓存便可。

1. 查找域名对应的ip地址，并修改hosts文件
```
$ nslookup github.global.ssl.fastly.Net

Non-authoritative answer:
Name:	github.global.ssl.fastly.Net
Address: 31.13.72.1

$ nslookup github.com

Non-authoritative answer:
Name:	github.com
Address: 52.74.223.119

在hosts文件末尾添加两行
sudo vim /etc/hosts
github.com 52.74.223.119
github.global.ssl.fastly.Net 31.13.72.1
```

2. 刷新DNS缓存
```
sudo /etc/init.d/networking restart
```


## win10 解决Github网页上图片显示失败的问题
打开hosts文件，末尾增加以下行, 2020/6/23整理：
```
# GitHub Start
140.82.113.3      github.com
140.82.114.20     gist.github.com

151.101.184.133    assets-cdn.github.com
151.101.184.133    raw.githubusercontent.com
151.101.184.133    gist.githubusercontent.com
151.101.184.133    cloud.githubusercontent.com
151.101.184.133    camo.githubusercontent.com
151.101.184.133    avatars0.githubusercontent.com
199.232.68.133     avatars0.githubusercontent.com
199.232.28.133     avatars1.githubusercontent.com
151.101.184.133    avatars1.githubusercontent.com
151.101.184.133    avatars2.githubusercontent.com
199.232.28.133     avatars2.githubusercontent.com
151.101.184.133    avatars3.githubusercontent.com
199.232.68.133     avatars3.githubusercontent.com
151.101.184.133    avatars4.githubusercontent.com
199.232.68.133     avatars4.githubusercontent.com
151.101.184.133    avatars5.githubusercontent.com
199.232.68.133     avatars5.githubusercontent.com
151.101.184.133    avatars6.githubusercontent.com
199.232.68.133     avatars6.githubusercontent.com
151.101.184.133    avatars7.githubusercontent.com
199.232.68.133     avatars7.githubusercontent.com
151.101.184.133    avatars8.githubusercontent.com
199.232.68.133     avatars8.githubusercontent.com

# GitHub End
```

[参考](https://blog.csdn.net/qq_38232598/article/details/91346392)


