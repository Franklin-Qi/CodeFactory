#ifndef HCNETSDK_H
#define HCNETSDK_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef	unsigned int			 DWORD;
typedef	unsigned short		 WORD;
typedef	unsigned short		 USHORT;
typedef	short							SHORT;
typedef	int								LONG;
typedef	unsigned char			BYTE;
typedef	unsigned int			 UINT;
typedef	void*							LPVOID;
typedef	void*							HANDLE;
typedef	unsigned int*			LPDWORD; 
typedef	unsigned long long UINT64;
typedef	signed long long	 INT64;



#define MAX_USERNUM_V30						32			//9000设备最大用户数
#define MACADDR_LEN					6			 //mac地址长度
#define MAX_CHANNUM_V40				 512
#define MAX_RIGHT					32		//设备支持的权限（1-12表示本地权限，13-32表示远程权限）
#define PASSWD_LEN					16			//密码长度
#define NAME_LEN					32			//用户名长度
#define SERIALNO_LEN				48			//序列号长度
#define NET_DVR_GET_USERCFG_V40										 6187		//获取用户参数
#define NET_DVR_SET_USERCFG_V40			 6188		//设置用户参数



/*IP地址结构体
 * sIpV4 
 * 设备IPv4地址 
 * sIpV6 
 * 设备IPv6地址 
 */

typedef struct NET_DVR_IPADDR
{  
  char    sIpV4[16];  
  BYTE    sIpV6[128];
}NET_DVR_IPADDR, *LPNET_DVR_IPADDR;



/*用户信息结构体。
 *
 * sUserName 
 * 用户名，只能用16字节 
 * sPassword 
 * 密码 
 * byLocalRight 
 * 本地权限，数组取值：0- 无权限，1- 有权限，每位数组表示一种权限：
 * 数组0: 本地控制云台
 * 数组1: 本地手动录象
 * 数组2: 本地回放
 * 数组3: 本地设置参数
 * 数组4: 本地查看状态、日志
 * 数组5: 本地高级操作(升级，格式化，重启，关机)
 * 数组6: 本地查看参数
 * 数组7: 本地管理模拟和IP Camera
 * 数组8: 本地备份
 * 数组9: 本地关机/重启 
 * byRemoteRight 
 * 远程权限，数组取值：0- 无权限，1- 有权限，每位数组表示一种权限：
 * 数组0: 远程控制云台
 * 数组1: 远程手动录象
 * 数组2: 远程回放 
 * 数组3: 远程设置参数
 * 数组4: 远程查看状态、日志
 * 数组5: 远程高级操作(升级，格式化，重启，关机)
 * 数组6: 远程发起语音对讲
 * 数组7: 远程预览
 * 数组8: 远程请求报警上传、报警输出
 * 数组9: 远程控制，本地输出
 * 数组10: 远程控制串口
 * 数组11: 远程查看参数
 * 数组12: 远程管理模拟和IP Camera
 * 数组13: 远程关机/重启 
 * dwNetPreviewRight 
 * 远程可以预览的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwLocalRecordRight 
 * 本地可以录像的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwNetRecordRight 
 * 远程可以录像的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwLocalPlaybackRight 
 * 本地可以回放的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwNetPlaybackRight 
 * 远程可以回放的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwLocalPTZRight 
 * 本地可以PTZ的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwNetPTZRight 
 * 远程可以PTZ的通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * dwLocalBackupRight 
 * 本地备份权限通道，从前往后顺序排列，遇到0xffffffff后续均为无效 
 * struUserIP 
 * 用户IP地址绑定(为0时表示允许任何地址) 
 * byMACAddr 
 * 物理地址绑定(为00:00:00:00:00:00时表示允许任何地址) 
 * byPriority 
 * 优先级：0xff-无，0-低，1-中，2-高
 * 无……表示不支持优先级的设置
 * 低……默认权限：包括本地和远程回放、本地和远程查看日志和状态、本地和远程关机/重启
 * 中……包括本地和远程控制云台、本地和远程手动录像、本地和远程回放、语音对讲和远程预览、本地备份、本地/远程关机/重启
 * 高……管理员（支持所有权限） 
 * byAlarmOnRight 
 * 报警输入口布防权限：0-无权限，1-有权限 
 * byAlarmOffRight 
 * 报警输入口撤防权限：0-无权限，1-有权限 
 * byBypassRight 
 * 报警输入口旁路权限：0-无权限，1-有权限 
 * byRes 
 * 保留，置为0 
 */

typedef struct NET_DVR_USER_INFO_V40
{  
    BYTE              sUserName[NAME_LEN];
    BYTE              sPassword[PASSWD_LEN];
    BYTE              byLocalRight[MAX_RIGHT];
    BYTE              byRemoteRight[MAX_RIGHT];
    DWORD             dwNetPreviewRight[MAX_CHANNUM_V40];
    DWORD             dwLocalRecordRight[MAX_CHANNUM_V40];
    DWORD             dwNetRecordRight[MAX_CHANNUM_V40];
    DWORD             dwLocalPlaybackRight[MAX_CHANNUM_V40];
    DWORD             dwNetPlaybackRight[MAX_CHANNUM_V40];
    DWORD             dwLocalPTZRight[MAX_CHANNUM_V40];
    DWORD             dwNetPTZRight[MAX_CHANNUM_V40];
    DWORD             dwLocalBackupRight[MAX_CHANNUM_V40];
    NET_DVR_IPADDR    struUserIP;  
    BYTE              byMACAddr[MACADDR_LEN];
    BYTE              byPriority;  
    BYTE              byAlarmOnRight;
    BYTE              byAlarmOffRight;  
    BYTE              byBypassRight;
    BYTE              byRes[118];
}NET_DVR_USER_INFO_V40,*LPNET_DVR_USER_INFO_V40;




/* 用户参数配置（扩展）结构体。
 * 成员说明：
 * dwSize:          结构体大小 
 * dwMaxUserNum:    设备支持的最大用户个数（只读） 
 * struUser:        用户信息，struUser[0]~struUser[dwMaxUserNum-1]有效 
 */
typedef struct NET_DVR_USER_V40
{  
  DWORD                    dwSize;
  DWORD                    dwMaxUserNum;
  NET_DVR_USER_INFO_V40    struUser[MAX_USERNUM_V30];
}NET_DVR_USER_V40,*LPNET_DVR_USER_V40;


//NET_DVR_Login_V30()参数结构
typedef struct NET_DVR_DEVICEINFO_V30
{
		BYTE sSerialNumber[SERIALNO_LEN];	//序列号
		BYTE byAlarmInPortNum;								//报警输入个数
		BYTE byAlarmOutPortNum;								//报警输出个数
		BYTE byDiskNum;										//硬盘个数
		BYTE byDVRType;										//设备类型, 1:DVR 2:ATM DVR 3:DVS ......
		BYTE byChanNum;										//模拟通道个数
		BYTE byStartChan;										//起始通道号,例如DVS-1,DVR - 1
		BYTE byAudioChanNum;								//语音通道数
		BYTE byIPChanNum;										//最大数字通道个数，低位	
		BYTE byZeroChanNum;						//零通道编码个数 //2010-01-16
		BYTE byMainProto;						//主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
		BYTE bySubProto;								//子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
		BYTE bySupport;				//能力，位与结果为0表示不支持，1表示支持，
		//bySupport & 0x1, 表示是否支持智能搜索
		//bySupport & 0x2, 表示是否支持备份
		//bySupport & 0x4, 表示是否支持压缩参数能力获取
		//bySupport & 0x8, 表示是否支持多网卡
		//bySupport & 0x10, 表示支持远程SADP
		//bySupport & 0x20, 表示支持Raid卡功能
		//bySupport & 0x40, 表示支持IPSAN 目录查找
		//bySupport & 0x80, 表示支持rtp over rtsp
		BYTE bySupport1;				// 能力集扩充，位与结果为0表示不支持，1表示支持
		//bySupport1 & 0x1, 表示是否支持snmp v30
		//bySupport1 & 0x2, 支持区分回放和下载
		//bySupport1 & 0x4, 是否支持布防优先级		
		//bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
		//bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
		//bySupport1 & 0x20, 表示是否支持rtsp over http		
		//bySupport1 & 0x80, 表示是否支持车牌新报警信息2012-9-28, 且还表示是否支持NET_DVR_IPPARACFG_V40结构体
		BYTE bySupport2; /*能力，位与结果为0表示不支持，非0表示支持														
										 bySupport2 & 0x1, 表示解码器是否支持通过URL取流解码
										 bySupport2 & 0x2,	表示支持FTPV40
										 bySupport2 & 0x4,	表示支持ANR
										 bySupport2 & 0x8,	表示支持CCD的通道参数配置
										 bySupport2 & 0x10,	表示支持布防报警回传信息（仅支持抓拍机报警 新老报警结构）
										 bySupport2 & 0x20,	表示是否支持单独获取设备状态子项
		bySupport2 & 0x40,	表示是否是码流加密设备*/
		WORD wDevType;							//设备型号
		BYTE bySupport3; //能力集扩展，位与结果为0表示不支持，1表示支持
		//bySupport3 & 0x1, 表示是否多码流
		// bySupport3 & 0x4 表示支持按组配置， 具体包含 通道图像参数、报警输入参数、IP报警输入、输出接入参数、
		// 用户参数、设备工作状态、JPEG抓图、定时和时间抓图、硬盘盘组管理 
		//bySupport3 & 0x8为1 表示支持使用TCP预览、UDP预览、多播预览中的"延时预览"字段来请求延时预览（后续都将使用这种方式请求延时预览）。而当bySupport3 & 0x8为0时，将使用 "私有延时预览"协议。
		//bySupport3 & 0x10 表示支持"获取报警主机主要状态（V40）"。
		//bySupport3 & 0x20 表示是否支持通过DDNS域名解析取流
		
		BYTE byMultiStreamProto;//是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
		BYTE byStartDChan;				//起始数字通道号,0表示无效
		BYTE byStartDTalkChan;		//起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
		BYTE byHighDChanNum;				//数字通道个数，高位
		BYTE bySupport4;				//能力集扩展，位与结果为0表示不支持，1表示支持
		//bySupport4 & 0x4表示是否支持拼控统一接口
		// bySupport4 & 0x80 支持设备上传中心报警使能。表示判断调用接口是 NET_DVR_PDC_RULE_CFG_V42还是 NET_DVR_PDC_RULE_CFG_V41
		BYTE byLanguageType;// 支持语种能力,按位表示,每一位0-不支持,1-支持	
		//	byLanguageType 等于0 表示 老设备
		//	byLanguageType & 0x1表示支持中文
		//	byLanguageType & 0x2表示支持英文
		BYTE byVoiceInChanNum;	 //音频输入通道数 
		BYTE byStartVoiceInChanNo; //音频输入起始通道号 0表示无效
		BYTE	bySupport5;	//按位表示,0-不支持,1-支持,bit0-支持多码流
		//bySupport5 &0x01表示支持wEventTypeEx ,兼容dwEventType 的事件类型（支持行为事件扩展）--先占住，防止冲突
		//bySupport5 &0x04表示是否支持使用扩展的场景模式接口
		/*
			 bySupport5 &0x08 设备返回该值表示是否支持计划录像类型V40接口协议(DVR_SET_RECORDCFG_V40/ DVR_GET_RECORDCFG_V40)(在该协议中设备支持类型类型13的配置)
			 之前的部分发布的设备，支持录像类型13，则配置录像类型13。如果不支持，统一转换成录像类型3兼容处理。SDK通过命令探测处理)
		*/
		BYTE	bySupport6;	 //能力，按位表示，0-不支持,1-支持
		//bySupport6 0x1	表示设备是否支持压缩 
		//bySupport6 0x2 表示是否支持流ID方式配置流来源扩展命令，DVR_SET_STREAM_SRC_INFO_V40
		//bySupport6 0x4 表示是否支持事件搜索V40接口
		//bySupport6 0x8 表示是否支持扩展智能侦测配置命令
		//bySupport6 0x40表示图片查询结果V40扩展
		BYTE	byMirrorChanNum;		//镜像通道个数，<录播主机中用于表示导播通道>
		WORD wStartMirrorChanNo;	//起始镜像通道号
		BYTE bySupport7;	 //能力,按位表示,0-不支持,1-支持
		// bySupport7 & 0x1	表示设备是否支持 INTER_VCA_RULECFG_V42 扩展
		// bySupport7 & 0x2	表示设备是否支持 IPC HVT 模式扩展
		// bySupport7 & 0x04	表示设备是否支持 返回锁定时间
		// bySupport7 & 0x08	表示设置云台PTZ位置时，是否支持带通道号
		// bySupport7 & 0x10	表示设备是否支持双系统升级备份
		// bySupport7 & 0x20	表示设备是否支持 OSD字符叠加 V50
		// bySupport7 & 0x40	表示设备是否支持 主从跟踪（从摄像机）
		// bySupport7 & 0x80	表示设备是否支持 报文加密
		BYTE	byRes2;				//保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

extern int	NET_DVR_Cleanup();
extern int	NET_DVR_Logout(LONG lUserID);
extern int	NET_DVR_Init();
extern LONG	NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
extern int	NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
extern int	NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
extern DWORD NET_DVR_GetLastError();



#ifdef __cplusplus
}
#endif


#endif
