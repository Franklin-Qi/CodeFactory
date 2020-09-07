# C语言代码中调用C++代码的方法示例
## 通过extern “C”调用
在 .cpp 文件中定义一个函数，声明为extern "C"，则该函数可以方便地在C代码中调用。
由于该函数在 .cpp 文件中定义，因而在该函数的实现中，可以调用任意的C++代码，
包括C++函数，创建C++类等等。

注：此种情况适用于有CPP源码情况，可以通过c_func调用cpp_func函数。
当只提供c++动态库时，应使用另一种通过dlopen/dlsym调用，在dl目录中。
```
#ifndef CPPFUNCTIONS_H_
#define CPPFUNCTIONS_H_

#ifdef __cplusplus
int cpp_func(int input);
extern "C" {
#endif

	int c_func(int input); // 在CPP文件中定义一个C函数，用于调用C++代码

#ifdef __cplusplus
}
#endif

#endif /* CPPFUNCTIONS_H_ */
```

参考：https://www.jb51.net/article/104482.htm
