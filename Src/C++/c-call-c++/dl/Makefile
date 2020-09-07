CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=-Wall -g
RM=rm -f

LDFLAGS=-shared -fPIC

#使用“wildcard”函数获取工作目录下的.cpp文件列表
CSRCS=$(wildcard *.c)
CXXSRCS=$(wildcard *.cpp)

#patsubst ：替换通配符
COBJS=$(patsubst %.c,%.o,$(CSRCS))
CXXOBJS=$(patsubst %.cpp,%.o,$(CXXSRCS))
OBJFILES=$(COBJS) $(CXXOBJS)

TARGET = test
LD_NAME= libCppLibTest.so
all:$(TARGET) $(LD_NAME)

$(LD_NAME): func.cpp
	$(CC) $(LDFLAGS) $^ -o $@

$(TARGET): main.c
	$(CC) $^ -o $@ -ldl

.PHONY:clean
clean:
	@$(RM) $(OBJFILES) $(TARGET) *.o $(LD_NAME)
