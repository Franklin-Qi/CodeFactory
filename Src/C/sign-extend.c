#include <stdio.h>

int get(const char *p)
{
    int t = 0;

    //t = (int) *p++; // 此时进行符号扩展，也就最高位为1
    t = (int) (unsigned char)*p++; // 此时进行符号扩展，也就最高位为0

    return t;
}

int main(int argc, char *argv[])
{
    int b = 0xAB; // 10x16 + 11 = 171
    char *p = &b;
    int a = 0;

    a = get(p);

    printf("b=%d a=%d\n", b, a);

    return 0;
}
