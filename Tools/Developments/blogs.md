# 博客园增加引用
[linux.cn](http://linuxidc.com/)
参照~/html-examples/codes/code.html
```
    <blockquote>
        <p>用我们最新的编程备忘单和指南来为新年开局，它适合所有技能水平的人。</p>
    </blockquote>
```
可以编辑完之后，进行html编辑,进行样式修改，如将引用插入指定html，或者直接引用编辑。


# 博客增加目录
href 内容为后台创建新分类，点击min缩小页面后的新分类地址。
```
    <div class="dropdown">
        <a href="#" class="dropbtn">每日阅读</a>
        <div class="dropdown-content">
            <a class="menu" href="https://www.cnblogs.com/yusq77/category/1623304.html"   target="_Blank" >晨间</a>
            <a class="menu" href="https://www.cnblogs.com/yusq77/category/1623306.html"   target="_Blank" >午间</a>
            <a class="menu" href="https://www.cnblogs.com/yusq77/category/1623307.html"   target="_Blank" >晚间</a>
    </div>
    </div>
```

# convert 更改图片像素大小
```
convert -resize  88x88 o_top5.png  top1.png
```
Convert o_top5.png to top1.png(88x88);

# 博客园top向上图标设置
top.png 像素应该尽量小，如48x48，之后在css中调整top.png 的width(<=48), height(<=48)

# 博客园默认最大
将默认页面保持最大，效果如点击变大MAX
```
#main_container{margin-left:-195px;}  
#leftmenu{display:none;}
```

# 如何从其他优秀博客参考css
[icon-top](F12 https://www.dingdabao.com/)
1. 复制通过查看器的html => 页首 HTML 代码
2. 样式规则的代码(.icon-top, .icon-top.cd-is-visible => css) 进行参考实现。

# 如何新增功能
[页面滚动超过一屏时显示返回顶部按钮](https://blog.csdn.net/u013372487/article/details/49785013)
参照本目录下toTop.css

1. scripts部分 => 页首 HTML 代码
2. stype,css ==> css
3. id=toTop, 引用css
```
<a href="#shwtop"><div id="toTop" style="zoom:90;"></div></a> 
```

# 更改目录导航的dt,dd
在sideBarContents dt *add=>* border: solid 2px #92ce30;


