# lambda表达式
lambda表达式用于python界面的中文翻译国际化，在程序入口模块进行使用。

## 实例
```
import gettext

_= lambda x: gettext.ldgettext("system-config-services", x)

zh_CN.po: 
msgid "Name"
msgstr "名称"

*.py: [_("Name")]

```
