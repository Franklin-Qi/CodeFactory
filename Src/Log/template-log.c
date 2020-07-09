
#include <syslog.h>

/*
 * 颜色参考：~/cs2c/log/color.h
 */
#define SYSLOG(format,...) \
    syslog(LOG_INFO, "["__FILE__":%05d]%s $ "format"\n",__LINE__,__func__,  ##__VA_ARGS__)  

#define GREEN(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;32m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)  
    
#define RED(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;31m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)  

#define YELLOW(format,...) \
    syslog(LOG_INFO, "%s["__FILE__":%05d]%s $ "format"%s\n","\e[0;33m",__LINE__,__func__,"\e[0m"  ##__VA_ARGS__)  

/** 
 * \file template-log.c
 *
 * openlog("MyLog", LOG_CONS | LOG_PID, LOG_LOCAL2);
 * RED("start");
 * closelog();
 */
   
   
   
