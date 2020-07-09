#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caja_write()
{
    FILE *fp = NULL;
    int begin=0, end = -1;

    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "%s\n%d\n%d\n", "你好", begin, end);
    fclose(fp);
}

int main(int argc, char *arcv[])
{
    caja_write();
    return 0;
}
