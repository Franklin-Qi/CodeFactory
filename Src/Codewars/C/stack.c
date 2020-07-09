#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * 栈的特性：先进后出。
 * 栈在计算语言处理和将递归算法改为非递归算法等方面起着非常重要的作用。
*/

#define INITSIZE 100    /* 储存空间的初始分配量 */
typedef int ElemType;

typedef struct
{
    int top;          /**<  栈顶指针 */
    ElemType *base;   /**<  存放元素的动态数组空间 */
    int size;         /**<  当前栈空间的大小 */
}Stack;

/** 初始化操作
 * 创建一个空栈，栈顶指针top初始化为0
 */
void init(Stack *s)
{
    s->base = (ElemType *)malloc(INITSIZE * sizeof(ElemType));      /**< 申请存储空间 */
    s->top = 0;                                                     /**< 栈顶指针初始值为0 */
    s->size = INITSIZE;                                             /**< 容量为初始值 */
}

/* 判栈S是否为空 */
int empty(Stack *s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}

/* 求栈长操作 */
int getlen(Stack *s)
{
    return (s->top);
}

/** 取栈顶元素操作
 *  将栈顶元素值存入e指向的内存单位，top值不变
 */
int top(Stack *s,ElemType *e)
{
    if(s->top==0)
        return 0;

    *e = s->base[s->top-1];      //栈顶元素值存入指针e所指向的内存单元
    return 1;
}

/** 压栈操作
 *  将入栈元素x存入top所指的位置上，然后栈顶指针top增1
 */
int push(Stack *s,ElemType x)
{
    if(s->top == s->size)
    {
        s->base = (ElemType *)realloc(s->base,(s->size+1)*sizeof(ElemType));
        if(!s->base)
            return 0;
        s->size++;
    }
    s->base[s->top++] = x;
    return 1;
}

/** 弹栈操作
 *  先将栈顶指针top减1，再将top单元中的元素存入指针e所指向的内存单元
 */
int pop(Stack *s,ElemType *e)
{
    if(s->top == 0)
        return 0;
    *e = s->base[--s->top];
    return 1;
}


/* 输出栈操作 */
void list(Stack *s)
{
    int i;
    for(i=s->top-1; i>=0; i--)
    {
        printf("%4d",s->base[i]);
    }
    printf("\n");
}
