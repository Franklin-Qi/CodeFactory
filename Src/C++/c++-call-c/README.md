# C++代码调用C代码
## 分别在包含的C头文件的开头和结尾加上如下的两个块
```
#ifndef __CFUNC_H
#define __CFUNC_H

#ifdef __cplusplus
extern "C" {
#endif

    int sum(int a, int b); // 调用的C代码声明

#ifdef __cplusplus
}
#endif


#endif
```
