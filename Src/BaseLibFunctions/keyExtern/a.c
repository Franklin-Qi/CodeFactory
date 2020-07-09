#include<stdio.h>

char original_name[1024];
int begin;
int end;

void test()
{
    begin = 0;
    end = 20;
    sprintf(original_name, "%s", "hello world");
}
