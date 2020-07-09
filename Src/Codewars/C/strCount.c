#include <stdio.h>
#include <stdlib.h>

int strCount(char *str, char *c)
{
    int num = 0;
    char *p = NULL;

    for(p = str; *p != '\0'; p++)
    {
        if(*p == c)
            num++;
    }
    return num;
}

void test(char *str, char *c)
{
    int num = 0;
    num = strCount(str, c);
    printf("strCount = %d\n", num);
}

int main()
{
    test("hello", "o");
    test("hello", "l");
    test("", 'z');

    return 0;
}
