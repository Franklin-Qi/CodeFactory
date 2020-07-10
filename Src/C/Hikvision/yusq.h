#ifndef _LOG_H_
#define _LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

   #define SIZE_16M               16777216  //1024*1024*16
   #define LOG_FILE_PATH          "/tmp/yusq.log"
   #define LOG_PARAMS             LOG_FILE_PATH,__FILE__,__func__,__LINE__
   #define STR_LEN_2048           2048
   #define VS_ERR 1 
   #define VS_OK  0

   extern  int debugy(char *pLogPath, char *pFile, const char *pFuncName, int iLineNumb, char *fmt, ...); 

#ifdef __cplusplus
}
#endif

#endif
