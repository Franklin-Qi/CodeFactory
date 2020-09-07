CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=-Wall -g
RM=rm -f

LDFLAGS=

#使用“wildcard”函数获取工作目录下的.cpp文件列表
CSRCS=$(wildcard *.c)
CXXSRCS=$(wildcard *.cpp)

#patsubst ：替换通配符
COBJS=$(patsubst %.c,%.o,$(CSRCS))
CXXOBJS=$(patsubst %.cpp,%.o,$(CXXSRCS))
#OBJFILE = $(COBJS:.c=.o) 也行
OBJFILES=$(COBJS) $(CXXOBJS)

TARGET = test
all:$(TARGET)

#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
$(TARGET):$(OBJFILES)
	$(CXX) $(LDFLAGS) $^ -o $@

#这个规则表示所有的 .o文件都是依赖与相应的.c文件的
%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY:clean
clean:
	@$(RM) $(OBJFILES) $(TARGET) *.o
