#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//void *libCPPTest = dlopen("/home/yusq/CodeFactory/Src/C++/c-call-c++/dl/libCppLibTest.so", RTLD_NOW);
	void *libCPPTest = dlopen("./libCppLibTest.so", RTLD_NOW);

    // _Z8cpp_funci 是readelf -s libCppLibTest.so |grep GLOBAL的符号，
    // 或通过 nm -D
    // 它通过binutils的工具c++filt demangle（解码）这个编译后的符号：
    // c++filt _Z8cpp_funci 可以获得函数名：cpp_func(int)
	int (*cpp_func)(int) = (int (*)(int))dlsym(libCPPTest, "_Z8cpp_funci");

	printf("cpp_func = %p\n", cpp_func);
	printf("cpp_func output = %d\n", cpp_func(10));

	return 0;
}
