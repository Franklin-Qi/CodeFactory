#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h> 
#include "log.h"
#include "HCNetSDK.h"


extern int debugInfo(char *pLogPath, char *pFile, const char *pFuncName, int iLineNumb, char *fmt, ...);


int main()
{
  NET_DVR_Init();  
  
  LONG lUserID;
  NET_DVR_DEVICEINFO_V30 struDeviceInfo;
  lUserID = NET_DVR_Login_V30("172.16.1.55", 8000, "admin", "123qwe!@#", &struDeviceInfo);
  if (lUserID < 0)
  {
    debugInfo(LOG_PARAMS ,  "Login error , %d \n" , NET_DVR_GetLastError());
    NET_DVR_Cleanup();
    return -1;
  }
  
  int iRet;
  DWORD dwReturnLen;
  NET_DVR_USER_V40 struParams = {0};
  //获取用户信息接口
  iRet = NET_DVR_GetDVRConfig(lUserID , NET_DVR_GET_USERCFG_V40 , 1, &struParams , sizeof(NET_DVR_USER_V40) , &dwReturnLen);
  if (!iRet)
  {
    debugInfo(LOG_PARAMS ,  "获取用户信息出错  \n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }

//帐户上收
#if 1
  //获取用户列表,用户名不能为空
  int i;
  for(i=0;i<MAX_USERNUM_V30;i++)
  {
    //获取所有用户名和密码
    //用户名为空时，不获取用户和密码，继续往下查询
    if(struParams.struUser[i].sUserName[0] == '\0') continue;
    debugInfo(LOG_PARAMS ,"sUserName: %s  sPassword: %s",struParams.struUser[i].sUserName,struParams.struUser[i].sPassword);
  }

#endif

//帐户查询
#if 0
  int i,j;
  BYTE user[16]={0};//用户名
  memcpy(user,"2",sizeof(user));

  //找到要获取用户信息的位置
  for(i=0;i<MAX_USERNUM_V30;i++)
  {
    if(strcmp((const char *)struParams.struUser[i].sUserName,user)==0)
    {
      j=i;
      break;
    }
  }
  //获取用户信息
  debugInfo(LOG_PARAMS ,"dwSize:%d  dwMaxUserNum:%d  length(struParams.struUser):%d  \n",struParams.dwSize,struParams.dwMaxUserNum,
    sizeof(struParams.struUser)/sizeof(NET_DVR_USER_INFO_V40));
  //用户名和密码
  debugInfo(LOG_PARAMS ,"sUserName: %s  sPassword: %s",struParams.struUser[j].sUserName,struParams.struUser[j].sPassword);
  
  //本地权限
  for(i=0;i< MAX_RIGHT ;i++)
  {
    debugInfo(LOG_PARAMS ,"byLocalRight: %d ",struParams.struUser[j].byLocalRight[i]);
  }
  debugInfo(LOG_PARAMS ,"\n");
  //远程权限
  for(i=0;i< MAX_RIGHT ;i++)
  {
    debugInfo(LOG_PARAMS ,"byRemoteRight : %d ",struParams.struUser[j].byRemoteRight[i]);
  }
  debugInfo(LOG_PARAMS ,"\n");
  //远程可以预览的通道
    debugInfo(LOG_PARAMS ,"dwNetPreviewRight : %d",struParams.struUser[j].dwNetPreviewRight[0]);
  //本地可以录像的通道
    debugInfo(LOG_PARAMS ,"dwLocalRecordRight :%d",struParams.struUser[j].dwLocalRecordRight[i]); 
  //优先级
  debugInfo(LOG_PARAMS ,"byPriority : %d",struParams.struUser[j].byPriority);
#endif

//帐户添加
#if 0
  BYTE user[16]={0};//用户名
  BYTE passwd[16]={0};//用户密码
  BYTE Priority;//用户优先级
  BYTE RemoteRight[MAX_RIGHT]={0,1,1,1,1,1,0,1,
                               1,0,1,0,0,1,0,0,
                               0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0};

  //用户参数值
  memcpy(user,"7",sizeof(user));
  memcpy(passwd,"123qwe!@#",sizeof(passwd));
  Priority=1;//操作员

  //设置用户信息
  //用户添加不允许重名
  int i;
  for(i=0;i<MAX_USERNUM_V30;i++)
  {
    if(strcmp((const char *)struParams.struUser[i].sUserName,user)==0)
    {
      debugInfo(LOG_PARAMS ," 用户添加不允许重名\n");
      NET_DVR_Logout(lUserID);
      NET_DVR_Cleanup();
      return -1;
    }
  }
  //找到要添加用户的位置
  int j;
  for(i=0;i<MAX_USERNUM_V30;i++)
  {
    if(struParams.struUser[i].sUserName[0]=='\0')
    {
      j=i;
      break;
    }
  }
  //设置用户名和密码
  memcpy(struParams.struUser[j].sUserName,user,sizeof(struParams.struUser[j].sUserName));
  memcpy(struParams.struUser[j].sPassword,passwd,sizeof(struParams.struUser[j].sPassword));
  //设置用户优先级
  struParams.struUser[j].byPriority=Priority;
  //设置用户远程权限
  for(i=0;i<MAX_RIGHT;i++)
  {
    struParams.struUser[j].byRemoteRight[i] = RemoteRight[i];
  }

  //调用参数设置函数
  iRet = NET_DVR_SetDVRConfig(lUserID, NET_DVR_SET_USERCFG_V40 , 1 , &struParams, sizeof(NET_DVR_USER_V40));
  if (!iRet)
  {
    debugInfo(LOG_PARAMS, "参数设置出错. \n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }
#endif

//帐户删除
//帐户为空，但是由于密码策略，密码不能为空，还是原有的密码
#if 0
  BYTE user[16]={0};//用户名
  BYTE passwd[16]={0};//用户密码

  //用户参数值
  memcpy(user,"7",sizeof(user));
  
  //找到要删除用户的位置
  int i,j=1;
  for(i=1;i<MAX_USERNUM_V30;i++)
  {
    if(strcmp((const char *)struParams.struUser[i].sUserName,user)==0) 
    {
      j=i;
      break;
    }
  }
  debugInfo(LOG_PARAMS ,"j: %d i:%d \n",j,i);
  //没找到需要删除的用户
  if((i == MAX_USERNUM_V30) && (j != MAX_USERNUM_V30 -1))
  {
    debugInfo(LOG_PARAMS ," 用户删除找不到用户\n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }

  //设置用户名和密码为空,也就是删除
  memset(struParams.struUser[j].sUserName,0,sizeof(struParams.struUser[j].sUserName));
  //由于密码策略，密码设置不为空，还是原有的密码
  memset(struParams.struUser[j].sPassword,0,sizeof(struParams.struUser[j].sPassword));

  //调用参数设置函数
  iRet = NET_DVR_SetDVRConfig(lUserID, NET_DVR_SET_USERCFG_V40 , 1 , &struParams, sizeof(NET_DVR_USER_V40));
  if (!iRet)
  {
    debugInfo(LOG_PARAMS, "参数设置出错. \n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }
#endif

//帐户改密
#if 0
  BYTE user[16]={0};//用户名
  BYTE passwd[16]={0};//用户密码

  //用户参数值
  memcpy(user,"1",sizeof(user));
  memcpy(passwd,"123qweASD",sizeof(passwd));

  //找到要更改密码用户的位置
  int i,j;
  for(i=1;i<MAX_USERNUM_V30;i++)
  {
    if(strcmp((const char *)struParams.struUser[i].sUserName,user)==0)
    {
      j=i;
      break;
    }
  }
  //没找到需要更改密码的用户
  if((i == MAX_USERNUM_V30) && (j != MAX_USERNUM_V30 -1))
  {
    debugInfo(LOG_PARAMS ," 用户改密找不到用户\n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }

  //更改用户密码
  memcpy(struParams.struUser[j].sPassword,passwd,sizeof(struParams.struUser[j].sPassword));

  //调用参数设置函数
  iRet = NET_DVR_SetDVRConfig(lUserID, NET_DVR_SET_USERCFG_V40 , 1 , &struParams, sizeof(NET_DVR_USER_V40));
  if (!iRet)
  {
    debugInfo(LOG_PARAMS, "参数设置出错. \n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }
#endif
#if 0
  debugInfo(LOG_PARAMS ,"password: %s \n", struParams.struUser[0].sPassword);

  debugInfo(LOG_PARAMS ,"usernumber: %d \n", sizeof(struParams.struUser)/sizeof(struParams.struUser[0]));
  debugInfo(LOG_PARAMS ,"dwReturnLen: %u \n",dwReturnLen); 
  int i,count=0,j=0; 
//struParams.struUser[i].sUserName[0]!='\0'
  for(i=0;i<MAX_USERNUM_V30;i++)
  {
   // if((struParams.struUser[i].sUserName[0]=='\0')||(struParams.struUser[i].sPassword[0]=='\0')) continue;
    debugInfo(LOG_PARAMS ,"[%d]%s%s\n",i, struParams.struUser[i].sUserName,struParams.struUser[i].sPassword);
    if(strcmp((const char *)struParams.struUser[i].sUserName,"123")==0) j=i;
    count++;
  }
  debugInfo(LOG_PARAMS ,"count: %d \n",count);
  debugInfo(LOG_PARAMS ,"j: %d \n",j);
  debugInfo(LOG_PARAMS ,"[%d]%s%s\n",j, struParams.struUser[j].sUserName,struParams.struUser[j].sPassword);
#if 1
#if 0
  BYTE user[16]; 
  BYTE passwd[16];
  memset(passwd,0,sizeof(passwd));
  memset(user,0,sizeof(user));
  memcpy(user,"",sizeof(user));
  memcpy(passwd,"123qweASD",sizeof(passwd));
#endif
  //memcpy(struParams.struUser[count].sUserName,user,sizeof(struParams.struUser[count].sUserName));
  BYTE passwd[16]={0};
  memcpy(passwd,"123qwe!@#",sizeof(passwd));
  memcpy(struParams.struUser[j].sPassword,passwd,sizeof(struParams.struUser[j].sPassword));
  iRet = NET_DVR_SetDVRConfig(lUserID, NET_DVR_SET_USERCFG_V40 , 1 , &struParams, sizeof(NET_DVR_USER_V40));
  if (!iRet)
  {
    debugInfo(LOG_PARAMS ,"NET_DVR_GetDVRConfig NET_DVR_SET_COMPRESSCFG_V30 error.\n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }
    debugInfo(LOG_PARAMS ,"[%d]%s%s\n",j, struParams.struUser[j].sUserName,struParams.struUser[j].sPassword);
#if 0 
#删除
  memset(struParams.struUser[j].sUserName,0,sizeof(struParams.struUser[j].sUserName));
  memset(struParams.struUser[j].sPassword,0,sizeof(struParams.struUser[j].sPassword));
  iRet = NET_DVR_SetDVRConfig(lUserID, NET_DVR_SET_USERCFG_V40 , 1 , &struParams, sizeof(NET_DVR_USER_V40));
  if (!iRet)
  {
    debugInfo(LOG_PARAMS, "NET_DVR_GetDVRConfig NET_DVR_SET_COMPRESSCFG_V30 error. \n");
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
    return -1;
  }
#endif 
  
 //debugInfo(LOG_PARAMS ,"user: %s  password :  %s \n",struParams.struUser[count].sUserName, struParams.struUser[count].sPassword);
#endif
#endif
  NET_DVR_Logout(lUserID);
  NET_DVR_Cleanup();
  
  return 0;

}
