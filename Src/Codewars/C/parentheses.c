#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validParentheses(const char* strin)
{
    int count1= 0, count2=0, count3= 0;
    char *s = NULL;

    for (s = strin; *s != '\0'; s++)
    {
        if (*s == '(') count1++;
        if (*s == '[') count2++;
        if (*s == '{') count3++;

        if (*s == ')' && count1 == 0) return false;
        if (*s == '[' && count2 == 0) return false;
        if (*s == '{' && count3 == 0) return false;

        if (*s == ')' && count1) count1--;
        if (*s == ']' && count2) count2--;
        if (*s == '}' && count3) count3--;
    }
    if (!count1 && !count2 && !count3)
        return true;
    else
        return false;
}

void test(const char *strin)
{
    if(validParentheses(strin))
        printf("True\n");
    else
        printf("False\n");

}
int main()
{
    test("()");
    test("(");

    return 0;
}
