# kylin-scanner
## 系统主题修改
src/plugins/ukui-feedback/ukuiFeedback.cpp
void feedback::style_changed(QString)

## github 提交规范
每一个commit，请根据情况选择如下模板：

新功能：

    Feature: xxx (新功能描述，比如：添加了窗口列表预览的功能)

        Link: xxx (禅道上需求的链接，没有的话，需要自己新建：禅道->项目->优麒麟20.04.1->添加研发需求)

bug修复:

    Fix: xxx （简要描述，比如：修复了时间排序的模式下文件不显示的问题）

    Link: xxx （禅道上的bug链接）

PS: git commit -am "Fix: xxxx; -> 这里直接按回车，即可换行

Link: xxxx"

## 翻译，保存文件汉化
/home/yusq/Qt5.14.2/5.14.2/Src/qttranslations/translations/
qt_zh_CN.ts 中拷贝以下行到项目ts文件中。
```
<context>
    <name>QPlatformTheme</name>
    <message>
        <location filename="qplatformtheme.cpp" line="+704"/>
        <source>Open</source>
        <translation>打开</translation>
    </message>
    <message>
        <location line="+18"/>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
</context>
<context>
    <name>QFileDialog</name>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="+515"/>
        <location line="+444"/>
        <source>All Files (*)</source>
        <translation>所有文件 (*)</translation>
    </message>
    <message>
        <location line="+222"/>
        <source>Directories</source>
        <translation>目录</translation>
    </message>
    <message>
        <location line="-3"/>
        <location line="+50"/>
        <location line="+1471"/>
        <location line="+75"/>
        <source>&amp;Open</source>
        <translation>打开(&amp;O)</translation>
    </message>
    <message>
        <location line="-1596"/>
        <location line="+50"/>
        <source>&amp;Save</source>
        <translation>保存(&amp;S)</translation>
    </message>
    <message>
        <location line="-730"/>
        <source>Open</source>
        <translation>打开</translation>
    </message>
    <message>
        <location line="+1515"/>
        <source>%1 already exists.
Do you want to replace it?</source>
        <translation>%1已经存在。
你想要替换它么？</translation>
    </message>
    <message>
        <location line="+20"/>
        <source>%1
File not found.
Please verify the correct file name was given.</source>
        <translation>文件%1
没有找到。
请核实已给定正确文件名。</translation>
    </message>
    <message>
        <location filename="../src/gui/itemviews/qdirmodel.cpp" line="+402"/>
        <source>My Computer</source>
        <translation>我的计算机</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="-1504"/>
        <source>&amp;Rename</source>
        <translation>重命名(&amp;R)</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>&amp;Delete</source>
        <translation>删除(&amp;D)</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>Show &amp;hidden files</source>
        <translation>显示隐藏文件(&amp;H)</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.ui"/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Back</source>
        <translation>后退</translation>
    </message>
    <message>
        <location/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Parent Directory</source>
        <translation>父目录</translation>
    </message>
    <message>
        <location/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>List View</source>
        <translation>列表视图</translation>
    </message>
    <message>
        <location/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Detail View</source>
        <translation>详细视图</translation>
    </message>
    <message>
        <location/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Files of type:</source>
        <translation>文件类型：</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="+6"/>
        <location line="+648"/>
        <source>Directory:</source>
        <translation>目录：</translation>
    </message>
    <message>
        <location line="+794"/>
        <location line="+862"/>
        <source>%1
Directory not found.
Please verify the correct directory name was given.</source>
        <translation>目录%1
没有找到。
请核实已给定正确目录名。</translation>
    </message>
    <message>
        <location line="-218"/>
        <source>&apos;%1&apos; is write protected.
Do you want to delete it anyway?</source>
        <translation>“%1“是写保护的。
你还是想删除它么？</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>Are sure you want to delete &apos;%1&apos;?</source>
        <translation>你确认你想删除“%1“？</translation>
    </message>
    <message>
        <location line="+15"/>
        <source>Could not delete directory.</source>
        <translation>不能删除目录。</translation>
    </message>
    <message>
        <location line="+407"/>
        <source>Recent Places</source>
        <translation>最近的地方</translation>
    </message>
    <message>
        <location line="-2550"/>
        <source>Save As</source>
        <translation>另存为</translation>
    </message>
    <message>
        <location filename="../src/gui/itemviews/qfileiconprovider.cpp" line="+411"/>
        <source>Drive</source>
        <translation>驱动器</translation>
    </message>
    <message>
        <location line="+3"/>
        <location line="+1"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location line="+29"/>
        <source>Unknown</source>
        <translation>未知的</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="-4"/>
        <source>Find Directory</source>
        <translation>查找目录</translation>
    </message>
    <message>
        <location line="+29"/>
        <source>Show </source>
        <translation>显示 </translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.ui"/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Forward</source>
        <translation>前进</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="+1970"/>
        <source>New Folder</source>
        <translation>新建文件夹</translation>
    </message>
    <message>
        <location line="-1963"/>
        <source>&amp;New Folder</source>
        <translation>新建文件夹(&amp;N)</translation>
    </message>
    <message>
        <location line="+656"/>
        <location line="+38"/>
        <source>&amp;Choose</source>
        <translation>选择(&amp;C)</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qsidebar.cpp" line="+418"/>
        <source>Remove</source>
        <translation>移除</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.cpp" line="-687"/>
        <location line="+652"/>
        <source>File &amp;name:</source>
        <translation>文件名称(&amp;N)：</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog.ui"/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Look in:</source>
        <translation>查看：</translation>
    </message>
    <message>
        <location/>
        <location filename="../src/gui/dialogs/qfiledialog_wince.ui"/>
        <source>Create New Folder</source>
        <translation>创建新文件夹</translation>
    </message>
    <message>
        <location filename="../src/gui/dialogs/qfiledialog_win.cpp" line="+160"/>
        <source>All Files (*.*)</source>
        <translation>所有文件 (*.*)</translation>
    </message>
</context>
```

## 配合libsane-dev和gdb进行调试
debuild 后进行安装dbgsysm字符串的包（类似-g生成的包，进行调试）,
进行编译libsane-dev的包，可以gdb进行行数判断。

## 在没有扫描仪情况下，调试编辑图片界面

## launchpad.dev没法登陆
目前只在火狐浏览器上可以，about:config 搜索preload，修改 
network.stricttransportsecurity.preloadlist 为false。

## 护网期间网络配置
1. hosts
192.168.30.200 launchpad.dev answers.launchpad.dev archive.launchpad.dev api.launchpad.dev bazaar.launchpad.dev bazaar-internal.launchpad.dev blueprints.launchpad.dev bugs.launchpad.dev code.launchpad.dev feeds.launchpad.dev keyserver.launchpad.dev lists.launchpad.dev ppa.launchpad.dev private-ppa.launchpad.dev testopenid.dev translations.launchpad.dev xmlrpc-private.launchpad.dev xmlrpc.launchpad.dev

192.168.240.110 kydcserver.kylin.com
192.168.0.175   distro.kylin.com
192.168.0.175   builder.kylin.com
192.168.6.176   pm.kylin.com
192.168.6.179   pm2.kylin.com
172.19.0.52     www.kylin.com
172.19.0.52     mail.kylin.com
172.19.0.52     sso.kylin.com
192.168.6.55    zsk.kylin.com

2. apt源
更正补充一下：
原v10.1ppa冻结，转正式版本v10.1系列，后续传包传新地址
系列代号定为 v101，对应版本号10.1，changelog写v101
版本系列地址： https://launchpad.dev/kylin-desktop/v101
源码包查看地址：https://launchpad.dev/+kylin/archive_publish?distro=kylin-desktop&series=v101
上传源码: dput dev:kylin-desktop/v101-proposed xxxx_source.changes
v10.1内网开发源：deb http://archive.launchpad.dev/kylin v101 main restricted universe multiverse

## 当修改源码后，debuild失败？
v10.1 13
ukui2004 12


1. 使用 dpkg-buildpackage -B
2. debian/compat: quilt => native

如果需要补丁包，则可以dpkg-source --commit 或者 quilt

## valgrind分析内存泄漏
分析内存泄漏有malloc_hook、mtrace、valgrind，mtrace每次要生成文件记录，
不方便经常调试。也只有valgrind一个选择。之前不用valgrind是因为代码用的库比较多，
libev、boost、STL...，其中libev文档指明valgrind对它的检测结果有误，
所以开始不用。不过现在也无所谓了，知道有这么回事就好。

sudo apt install valgrind

之后在qtcreator中进行分析-》valgrind内存分析

## cppcheck静态代码检查
```
function mycppcheck {
    cppcheck --enable=warning,style,performance "$1" 2>err.txt; vi err.txt
}
```

## 初始ukui需要安装的依赖软件
sudo apt install openssh-server
                 libopencv-dev
                 vim git ctags
                 sane sane-utils xsane libsane-dev libsane
                 libglib2.0-dev
                 tesseract-ocr tesseract-ocr-eng tesseract-ocr-chi-sim libleptonica-dev liblept5 libtesseract-dev
                 qtcreator qt5-default qttools5-dev-tools //这个有问题，需要在官网进行下载版本并安装

注：
自己生成的kylin-scanner包可以通过以下方式解决依赖问题：
sudo dpkg -i *.deb
sudo apt install -f
sudo dpkg -i *.deb


v10 arm的depends cannot handle, it can be showed in qtcreator.

## 提示Kit不存在
sudo apt install qt5-default qttools5-dev-tools
option -> qt version -> 选择qmake路径为/usr/lib/qt5/bin/qmake

## 提示gio-2.0 失败
sudo apt install libglib2.0-dev

## 提示sane失败，没找到sane.h头文件
sudo apt install sane sane-utils xsane

## 颜色转换
RGB <==> hex
https://www.sioe.cn/yingyong/yanse-rgb-16/

## debuild 遇到了dpkg-deb: error: subprocess returned error exit status 2
将../下除了kylin-scanner项目以外的文件都删除
refer to : https://blog.csdn.net/fearlessxjdx/article/details/105230855

## lintian 是否通过和结果修改

一. lintian检查是否通过:
自动调用 可以在pdebuild、debuild时自动调用，详见相关说明文件。
手动处理 debuild、pdebuild编包后会生成foo-version.amd64.changes文件,对其运行lintian, 解决全部报告的"E"和"W",其他的标注尽量解决(常见lintian错误和解决方法):
> lintian -i -EvIL +pedantic --verbose ../kylin-scanner_1.0.0_amd64.changes > lintian.txt


二. 结果修改
里面E(错误) 和 W(警告)，需要处理下，其他的P和I尽量处理

1. debian/control:
decriptions: 每行不超过80，通过.vimrc设置set cc=80进行判断

2. debian/watch:
2.1 debian-watch-file-in-native-package:
refer to https://wiki.debian.org/DEHS
         https://wiki.debian.org/debian/watch
add:

version=4
opts=filenamemangle=s/.+\/v?(\d\S+)\.tar\.gz/kylin-scanner-$1\.tar\.gz/ \
  https://github.com/ukui/kylin-scanner/releases .*/v?(\d\S+)\.tar\.gz

删除debian/watch,不保存

3. debian/copyright
3.1 file-without-copyright-information xxx
将xxx 放到debian/copyright 中

3.2 bug1: missing-license-text-in-dep5-copyright
在License 下应该添加文本，而且不应该全段证书内容，只需要最开始的几段

3.3 bug2: ambiguous-paragraph-in-dep5-copyright
在files字段范围内，没有多余空行

3.4 dep5-copyright-license-name-not-unique gpl-3
本段定义了已经定义的许可证。
根据规范，简短的许可证名称在单个版权文件中必须唯一

license下的值不能一样,GPL-3.0, GPL+-3.0可以

3.5 copyright-file-contains-full-gpl-license
GPL+-3.0 下应该改为GPL3，同时不应该包括所有的证书内容

4. debian/changelog
4.1 changes: bad-distribution-in-changes-file unstable
将unstable 改为 trusty, focal, raring, focal-proposed
参考 https://www.debian.org/doc/debian-policy/ch-docs.html#s-changelogs
vi  /usr/share/doc/packagekit/changelog.Debian.gz

5. debian/compat
5.1 dh: error: Please specify the compatibility level in debian/compat
compat 不能删除，应该保留，比如设为11

```


## 为了能正确地与上游ubuntu的包比较版本号大小
请按以下规范确定v10.1和v10版本中修改的软件包的版本号。
自研包：版本号要遵守debian规范：末尾必须是数字、版本号中不能有超过一个“-”、
        源码格式为native的包版本号不要包含“-”。自研包版本号包含kord的都去掉，也不需要添加kylin关键字
修改的上游的包规范：
https://uq76pac93x.feishu.cn/docs/doccn5FmGiQtwIL1XEs5iChjT4c#MnEEUp

## qt app 4k支持
目前发现一个严重bug，某些型号国产2k屏笔记本上默认放大了一倍，大家先采用临时解决办法:
加一个分辨率的判断
```
if (QApplication::desktop()->width() >= 2560) {
        #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
                QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
                QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
        #endif
    }
```


## 请软件开发者熟读以下文档
了解Debian/control文件如何处理软件包之间的关系：https://www.debian.org/doc/debian-policy/ch-relationships.html

## 更改svg图标的颜色
使用编辑器vim打开min_white.svg，增加fill="#fff"，将黑色变为白色

## 不同主题的图标放置
$ apt-file search kylin-video.png
$ apt-file list ubuntukylin-theme  | grep kylin-video

## 如何支持多台扫描设备
将搜索和连接设备接口进行拆开，这样就能显示多台设备了。

多台设备分类：
1. 同一台设备，通过一个USB，读出本地和HTTP2台设备
2. 2台设备，读出2个设备
3. 2台设备，读出2+个设备
4. 多设备的界面可能设置成弹窗，这种情况需要统一接口给界面调用

针对1， 怎么区分设备类型呢？平板式或馈纸式
同一个设备的不同方式，一个为本地，一个为http
使用model和http标识进行判断

增加一个find_device接口

接下来需要处理选择不同设备名称时的函数处理。

tips:
1. 在widge.cpp 上有几个界面的对象，可以在指定文件新增函数，widget.cpp直接调用
2. 本类中的函数直接调用，不用通过信号和槽函数，槽函数有时候会失败

xsane不能打印HTTP的设备，Scala语言的simple-scan可以打印，所以可以查看simple-scan的函数。
通过simple-scan的查看，可以发现参数出错发生在分辨率和尺寸的设置和读取这块。
查看日志进行定位到log_option() 可以获取对应扫描参数

> HTTP的分辨率在opt->type == 3 时，是进行INT类型；
> HTTP的尺寸是tl_x => 7 tl_y => 8 br_x => 9 br_y => 10 

如何编译simple-scan ?
cd simple-scan/ ; bash simple-scan-autobuild.sh

如何查看simple-scan日志?
vi ~/.cache/simple-scan/simple-scan.log

## 做完初始包后，提供的文件
kylin-scanner-1.0.0/ 是通过 dpkg-source -x kylin-scanner_1.0.0.dsc 生成的。
```
kylin-scanner-1.0.0
kylin-scanner_1.0.0_amd64.build
kylin-scanner_1.0.0_amd64.buildinfo
kylin-scanner_1.0.0_amd64.changes
kylin-scanner_1.0.0.dsc
kylin-scanner_1.0.0.tar.xz
```

##  两个仓库同步
1. diff和patch对两个仓库进行同步,

kylin-scanner-1是新fork的仓库，kylin-scanner是有修改的仓库，比kylin-scanner-1更新
```
diff -Nura kylin-scanner-1/src/ kylin-scanner/src/ > src.patch
cd kylin-scanner-1/
patch -p1 < ../src.patch
```

2. git diff 和 git apply 对两个仓库进行同步
```
cd kylin-scanner/
git diff commitID1 commitID2 > src.patch
cd kylin-scanner-1/
git apply ../src.patch
git status
```


## kylin-scanner Qt的实现

### 需求分析
> kylin-scanner 麒麟扫描的设计稿已经比较完善和详细了。
> 设计师和开发者不可能构想到和实现所有的需求。我们需要
> 为未知的需求留下余地，以便快速实现需求。同事保证kylin-scanner
的发展不会受到这些需求的阻碍。

### 设计思路
> 底层选择
> 前后端分离的设计模式
> 可扩展的应用形式（插件）
> 使用系统的主题（与系统的主题保持一致）
> 关键环节

1. 底层选择
如何寻找满足需求和我设计思路的框架？
> 效率
> 稳定性
> 底层框架熟练程度
我认为，对于一个开发者而言，如果要实现同样的项目需求，那么通过效率、
稳定性和底层框架的熟练程度这三点，基本可以决定如何进行底层选择
(这里以重写为出发点)。


2. 前后端分离的设计模式
接口的设计和扩展的实现？

技术原理：使用Qt 的model/view编程
基于已有的理论体系，让自己想法更清晰，也就是基于技术，
反过来划分和理清思路。这样带来的结果是--思路和技术理论能够
螺旋上升式的进步。

> 数据不会因视图类型的改变而改变
> 多种视图可以通过统一的接口实现统一数据的不同展示方式
> 不同的视图可以通过同样的逻辑和接口对数据进行操作

3. 可扩展的应用形式
技术原理: 基于Qt的插件机制设计可扩展框架与插件
> 可扩展接口设计
> 内部接口实现和外部接口实现相结合
> 对用户隐藏二者的区别，但提供扩展的管理

4. 使用系统的主题
关键环节：
> 找到Qt可以使用现有系统主题的方法
> 系统的主题和图标主题必须规范化

技术原理：基于Qt的Gtk主题插件实现系统主题的同步。

风格切换？
4.1 如何通过控制面板切换主题？
4.2 如何在gnome桌面上运行kylin-scanner？

充分利用现有资源
> 为每个应用程序编写样式表是没有效率的做法
> 系统主题在不断迭代和更新中


## 总结
> 从零实现的思路
> 站在用户角度，想得比现有需求更多，注重学习和提升


## 总体设计
后端功能检测可以通过`scanimage -L`(属于sane-utils) 查找设备。
```
scanimage --device-name=pixma:04A91912_435F94 --resolution=300 --format=jpeg >scanner.jpg
```

前端界面如下：
### 1. widget.cpp:
用于组合标题栏（titleBar.cpp），功能栏（funcBar.cpp），扫描设置栏（scanSet.cpp），
扫描图片显示栏（scanDisplay.cpp）界面，同时也是连接各个文件信号之前的纽带。

不同组合控件之间的信号连接，都需要在widget.cpp 上进行connect。

### 2. titleBar.cpp
用于标题栏的界面设计，如放大、缩小和关闭按钮。

### 3. funcBar.cpp
用于功能栏界面设计，如一键美化、智能纠偏、文字识别和普通扫描按钮。

### 4. scanDisplay.cpp
用于扫描图片显示界面设计，包括各种界面以及编辑框设计。

### 5. 其他文件
embelish.cpp：美化功能，oneClickEmbelish()直接美化指定目录的扫描图片

interruptDlg.cpp: 创建扫描中断界面，显示各种中断错误信息。

kylinCmb.cpp: 自定义组合框combobox控件，包括tooltip的美化。

kylinSane.cpp: 后端扫描接口，使用单例模式进行共享一个单例对象。
