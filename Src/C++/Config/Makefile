CXX=g++
CXXFLAGS=-Wall -g
RM=rm -f

LDFLAGS=

#使用“wildcard”函数获取工作目录下的.cpp文件列表
SRCS=$(wildcard *.cpp)

#patsubst ：替换通配符
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

TARGET = test

#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
$(TARGET):$(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

#这个规则表示所有的 .o文件都是依赖与相应的.c文件的
%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY:clean
clean:
	@$(RM) *.o $(TARGET)
