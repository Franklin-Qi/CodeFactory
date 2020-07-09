//////////////////////////////////////////////////////////////////////
// Author: Zhang QuanLin
// Creation Time: 05/28/2008
// Description:
//
// Change History
// 05/28/2008 Htcpvs.cpp created

///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#define DEFAULT_LOG_FILE		"./LogCheck.log"
#define INI_FOR_CENTOS5     "./HacCheck.ini"
#define INI_FOR_CENTOS7     "./HacCheck.centos7.ini"
#define LOGPATH             "/tmp"
#define BUFFSIZE            8192
/**
 * 函数功能：将时间转成系统时间
 * 函数参数：secs为time(NULL)值
 * 返回值：  转换成系统时间的字符串
 */
char *LogChgTime2Str(unsigned long  secs)
{
  static char buf[64];
  time_t ltime = (time_t)secs;
  struct tm *today;

  today = localtime( &ltime );
  sprintf(buf,"%d-%02d-%02d %02d:%02d:%02d # ",\
      today->tm_year+1900, today->tm_mon+1, today->tm_mday,\
      today->tm_hour, today->tm_min, today->tm_sec );
  return buf;
}

/**
 * 函数功能：将日志写入到指定的文件中
 * 函数参数：格式化字符串
 * 返回值：  写入成功则返回写入的字符数，否则为负数
 */ 
int HacCheckLog( char *fmt, ... )
{
    FILE *fp = NULL;
    char buf[512];

    int n;
    va_list args;

    va_start(args, fmt);
    n = vsprintf(buf, fmt, args);
    va_end(args);

    fp = fopen( DEFAULT_LOG_FILE, "a" );
    if( fp )
    {
      buf[n] = '\0';
      fprintf( fp, "%s %s", LogChgTime2Str(time(NULL)), buf );
      fclose( fp );
    }

    return n;
}

/**
 * 函数功能：得到系统版本信息
 * 函数参数：无
 * 返回值：  系统版本信息的关键字
 */
int GetSystemMainVersion()
{
  char version[256] = {0};
  FILE *fp = fopen("/etc/redhat-release", "r");
  fread(version, sizeof(version) - 1, 1, fp);
  fclose(fp);
  HacCheckLog("%s \n",strstr(version,"release 7"));
  if (strstr(version, "release 7")) return 7;   //strstr函数匹配指定字符串并返回地址
  return 5;
}

/**
 * 函数功能：根据版本信息得到系统配置文件名
 * 函数参数：无
 * 返回值：  系统配置文件名字符串
 */
const char* GetIniFileName()
{
  int version = GetSystemMainVersion();
  if (version == 7) return INI_FOR_CENTOS7;
  return INI_FOR_CENTOS5;
}

/**
 * 函数功能：执行Linux指定命令，获取指定文件大小
 * 函数参数：Linux空间大小
 * 返回值：  无
 */
void GetLeftLogSpace(int &value)
{
  FILE *fLog = NULL;
  char cmdStr[256] = {0};
  char result[BUFFSIZE] = {0}; 
  sprintf(cmdStr,"df -k -P %s | sed -n 2p | awk '{printf \"%%d\\n\", $4 / 1048576}'",LOGPATH);
  HacCheckLog("cmdStr: %s\n",cmdStr);
  if( (fLog = popen(cmdStr, "r")) == NULL )
  {
    HacCheckLog("* popen() error!\n" );
    exit(1);

  }
  fgets(result, BUFFSIZE, fLog);
  value = atoi(result);
  pclose(fLog);
}



int main(int argc, char **argv)
{
  int a = 0;
  GetLeftLogSpace(a);
	HacCheckLog( "version : %s %d\n", GetIniFileName(),a);

    return 0;
}
