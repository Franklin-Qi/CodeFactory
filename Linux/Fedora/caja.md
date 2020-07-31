## Longsn B62.3 修改
### 问题描述
选中桌面文件->鼠标拖拽文件到U盘->此时U盘内文件与桌面文件同时被选中，
按delete键，删除的是桌面的文件。

注：B62.3 iso 地址:
http://10.1.80.209/REPO/ND7U2/LS/ISO/REL/BUILD62.3/0707/

### 确定修改标准
修改为与win一致：
当拖拽桌面文件到U盘中时，桌面文件不选中，而U盘中文件选中，
此时delete则删除U盘中的文件。


## caja 手动新建文件重叠到第一个图标处

========v10 caja 日志打印 ========
<syslog.h> => 日志打印头文件
第一种方式：
    openlog("test", LOG_CONS | LOG_PID, LOG_AUTHPRIV); => 打开日志开关
    syslog(LOG_AUTHPRIV | LOG_WARNING, "==shuoqi.yu==%s==%s==%d=\n", __FILE__, __func__, __LINE__); => 日志打印
    closelog(); => 关闭日志开关，最好每次打印时，都复制这3行

$ journalctl -f => 日志查看

第二种方式： => 需要在/etc/rsyslog.conf末尾增加一行: local2.* /var/log/mylog , 并执行 systemctl restart rsyslog.service

   openlog("myLog", LOG_CONS | LOG_PID, LOG_LOCAL2);
   syslog(LOG_INFO, "==shuoqi.yu==%s==%s==%d=\n", __FILE__, __func__, __LINE__); => 日志打印
   closelog(); => 关闭日志开关，最好每次打印时，都复制这3行

$ tail -f /var/log/mylog => 日志查看
========v10 caja 日志打印 ========

=========v10 caja 调试步骤 start=========
cd caja-241/caja-1.12.7/ =>进入源文件
vim libcaja-private/caja-icon-container.c => 修改文件
quilt add libcaja-private/caja-file-operations.c => 增加补丁文件
quilt refresh => 刷新
debuild -b -j4 => v10做补丁包
cd ..  => caja-241/目录下进行安装修改后的包
sudo dpkg -i caja_1.12.7-1kord0k241_amd64.deb caja-common_1.12.7-1kord0k241_all.deb gir1.2-caja_1.12.7-1kord0k241_amd64.deb libcaja-extension
1_1.12.7-1kord0k241_amd64.deb
ps -ef | grep caja 
kill 29087 => 由于caja会自动加载，所以找到当前的caja进行kill
=========v10 caja 调试步骤 end=========


================================================================================分析开始
src/file-manager/fm-list-view.c => 列表视图
src/file-manager/fm-directory-view.c => 图标视图，也就是平常的视图
	signals[ADD_FILE] =
		g_signal_new ("add_file",
		              G_TYPE_FROM_CLASS (klass),
		              G_SIGNAL_RUN_LAST,
		              G_STRUCT_OFFSET (FMDirectoryViewClass, add_file),
		              NULL, NULL,
		              fm_marshal_VOID__OBJECT_OBJECT,
		              G_TYPE_NONE, 2, CAJA_TYPE_FILE, CAJA_TYPE_DIRECTORY);

add_file 定义到 src/file-manager/fm-directory-view.h
    /* The 'add_file' signal is emitted to add one file to the view.
     * It must be replaced by each subclass.
     * 也就是说这里是虚函数，具体实现看子对象，可以根据G_OBJECT
     */
    void    (* add_file) 		 (FMDirectoryView *view,
                                  CajaFile *file,
                                  CajaDirectory *directory);
具体子对象实现，进行查找
$ grep -wnr "add_file" src/

src/file-manager/fm-empty-view.c:293:    fm_directory_view_class->add_file = fm_empty_view_add_file;
src/file-manager/fm-list-view.c:3413:    fm_directory_view_class->add_file = fm_list_view_add_file;
src/file-manager/fm-icon-view.c:3371:    fm_directory_view_class->add_file = fm_icon_view_add_file;
src/file-manager/fm-computer-view.c:3875:    fm_directory_view_class->add_file = fm_computer_view_add_file;

src/file-manager/fm-icon-view.c
    FMDirectoryViewClass *fm_directory_view_class; => 父对象结构体指针,相当于父对象

    fm_directory_view_class = FM_DIRECTORY_VIEW_CLASS (klass);

    G_OBJECT_CLASS (klass)->set_property = fm_icon_view_set_property;

    fm_directory_view_class->add_file = fm_icon_view_add_file; => 初始化，相当于c++的构造函数，指定
        子对象add_file实现函数在fm_icon_view_add_file() 

    fm_icon_view_add_file => caja_icon_container_add

libcaja-private/caja-icon-container.c
   caja_icon_container_add => schedule_redo_layout => redo_layout_callback => redo_layout_internal
   redo_layout_internal() 中进行修改手动排列中add_file的图标与第一个重叠

    /* Run an idle function to add the icons. */
    schedule_redo_layout (container);


    CajaIconContainer *icon_container;
    if(caja_icon_container_get_is_desktop(icon_container)) => 图标是在桌面上的
    {
        if(!desktop_has_no_icons)
            desktop_has_no_icons = TRUE;
    }

    if (container->details->auto_layout => 图标排列是手动
            && container->details->drag_state != DRAG_STATE_STRETCH)
    {
        resort (container);
        lay_down_icons (container, container->details->icons, 0); => 排列图标
    }

    redo_layout_internal => lay_down_icons 进行排列图标
        lay_down_icons_horizontal (container, icons, start_y); => 水平的排列图标
            lay_down_one_line (container, line_start, p, y, max_height_above, positions, FALSE); => 排列一行
                icon_set_position() => 设置图标位置
                    container_top =  container_y / pixels_per_unit + 5; => **图标上限+5，所以没有短横**

        lay_down_icons_vertical_desktop1 (container, icons); => 竖直的排列图标
            lay_down_one_column() => 排列一列
                icon_set_position() => 设置图标位置
                    container_top =  container_y / pixels_per_unit + 5; => 图标上限+5，所以没有短横



## 快捷方式批量移动时，会重叠
解决方案：
处理方案为当移动桌面图标到超过屏幕的宽度时，图标进行从右到左放置，
同时在图标已满的情况下，还按照原有流程放置多余图标到右上角。

新建图标在满的时候，仍按照原流程放置多余图标在右上角。

libcaja-private/caja-icon-container.c 
realize -> caja_icon_dnd_init  (dnd: drag and drop 拖动和放下)
=> libcaja-private/caja-icon-dnd.c
    drag_begin_callback
    drag_end_callback

libcaja-private/caja-icon-container.c 

选中15个icons, 循环snap_position()进行打印屏幕分辨率15次
caja_icon_container_unstretch => caja_icon_container_move_icon 

Functions:

// 判断当前网格位置是否为空(是否有其他图标在该位置)，
// 返回为TRUE时，表示当前位置没有其他图标，可以放置图标，不用再循环找下一个坐标位置
placement_grid_position_is_free()

// 桌面图标可以从左往右进行查找空位置，输入的是第一个xy(top-left)坐标，返回的是找到的xy坐标
// 寻找空位置的判断条件为是否在新行(y值超过屏幕高度) || 当前图标位置是否为空 
// 不开启新行，当前坐标为空，则可以返回当前坐标，然后设置图标位置放置在当前位置
find_empty_location() 

// 新增桌面图标可以从右往左进行查找空位置，输入的是第一个xy(top-left)坐标，返回的是找到的xy坐标
find_empty_location() 

// 设置图标位置，只要设定就可以在桌面上该坐标(top-left)位置显示图标
icon_set_position() 

// 可以排列桌面图标
align_icons()



