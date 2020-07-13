# kylin-scanner

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


