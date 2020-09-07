#include "func.h"

int cpp_func(int input)
{
	return 5;
}

/*
 * 在 .cpp 文件中定义一个函数，声明为extern "C"，
 * 则该函数可以方便地在C代码中调用。由于该函数在 .cpp 文件中定义，
 * 因而在该函数的实现中，可以调用任意的C++代码，包括C++函数，创建C++类等等。
 */
int c_func(int input)
{
	return cpp_func(input);
}
