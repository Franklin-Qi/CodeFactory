#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

/*
 * 颜色参考：~/cs2c/log/color.h
 */
#define DEBUGGREEN(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;32m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)

#define DEBUGRED(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;31m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)

#define DEBUGYELLOW(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;33m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)

static int debug_setting = 0;

void show_name()
{
    //DEBUGRED("%s", "begin");   xxx not work
    DEBUGRED("begin");
    syslog("test = %s", "test");
}

void myfunc()
{ DEBUGGREEN("start");
}

void myfunc1()
{ DEBUGYELLOW("start");
}

int
main(int argc, char **argv)
{
   openlog("MyLog", LOG_CONS | LOG_PID, LOG_LOCAL2);

   if(getenv("MYDEBUG"))
       debug_setting = 1;

   if(debug_setting)
   {
       DEBUGGREEN("test");
   }

   show_name();
   myfunc1();
   myfunc();

   closelog();
   return 0;
}
