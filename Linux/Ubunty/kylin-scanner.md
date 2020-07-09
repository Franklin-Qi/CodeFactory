# kylin-scanner

## 不同主题的图标放置
$ apt-file search kylin-video.png
$ apt-file list ubuntukylin-theme  | grep kylin-video

## 如何支持多台扫描设备
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

