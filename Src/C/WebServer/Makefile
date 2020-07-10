all:client server

CC = gcc 
CFLAGS = -Wall -c
#–Wno-unused-but-set-variable 意思就是变量没有被使用。要是我们不想看到这样的警告

#LDFLAGS告诉链接器寻找库文件的路径
#LDFLAGS = -lpthread

#wildcard : 扩展通配符,在Makefile规则中，通配符会被自动展开。但在变量的定义和函数引用时，通配符将失效。这种情况下如果需要通配符有效，就需要使用函数“wildcard”
#使用“wildcard”函数获取工作目录下的.c文件列表
#SRCS = $(wildcard *.c)

#patsubst ：替换通配符
#OBJS = $(patsubst %.c,%.o,$(SRCS))

#TARGET = fopen point
TARGET = client server

#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
#$(TARGET):$(OBJS)
#point: point_function.o 
#	$(CC) $(LDFLAGS) -o $@ $^

#fopen: fopen.o 
#	$(CC) $(LDFLAGS) -o $@ $^

client:client.o 
	$(CC) $(LDFLAGS) -o $@ $^
server:server.o
	$(CC) $(LDFLAGS) -o $@ $^

#这个规则表示所有的 .o文件都是依赖与相应的.c文件的
%.o:%.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY:clean
clean:
	@rm -f *.o $(TARGET)
