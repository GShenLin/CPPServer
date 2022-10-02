#ifndef __IDEFINE_H
#define __IDEFINE_H
#include <vector>

#ifdef __WIN32_
#include<winsock2.h>
#pragma comment(lib,"ws2_32")



#define RELEASE_POINTER(p) {if(p!=NULL) {delete p; p = NULL;}}
#define RELEASE_HANDLE(h) {if(h!=NULL && h != INVALID_HANDLE_VALUE) {CloseHandle(h); h = INVALID_HANDLE_VALUE;}}
#define RELEASE_SOCKET(s) { if (s != INVALID_SOCKET) { closesocket(s); s = INVALID_SOCKET; }}

#endif // __WIN32_


//定义最大用户数 因为采用预分配的方式 所有用户的连接ID进行缓存
#define MAX_USER_SOCKETFD 1000000

//工程路径字符串的最大长度
#define MAX_EXE_LEN  200

//文件名最大长度
#define MAX_FILENAME_LEN 250

//心跳包的宏定义
#define SIO_KEEPALIVE_VALS IOC_IN | IOC_VENDOR | 4

//  MD5验证时的最大长度
#define MAX_MD5_LEN  35

//IP地址的最大长度
#define MAX_IP_LEN 20

//打印方式协定
#define LOG_MSG printf

typedef signed char				s8;
typedef signed short				s16;
typedef signed int					s32;
typedef signed long long 		s64;
typedef unsigned char			u8;
typedef unsigned short			u16;
typedef unsigned int				u32;
typedef unsigned long long	u64;

//定义一些Socket状态
namespace func {
	//socket关闭原因
	enum SOCKET_CLOSE
	{
		S_CLOSE_FREE = 0,
		S_CLOSE_ACCPET = 1,
		S_CLOSE_SHUTDOWN = 2,
		S_CLOSE_CLOSE = 3
	};

	//socket服务端状态
	enum SOCKET_CONTEXT_STATE
	{
		SC_WAIT_ACCEPT = 0,
		SC_WAIT_RECV = 1,
		SC_WAIT_SEND = 2,
		SC_WAIT_RESET = 3
	};

	//socket客户端连接状态
	enum SOCKET_STATE
	{
		S_Free = 0,
		S_Connect = 1,
		S_ConnectSecure = 2,
		S_Login = 3,
		S_NeedSave = 4,
		S_Saving  = 5
	};

	struct ConfigXML
	{
		s32 ID; //当前应用程序ID
		u8 Type; //当前应用程序的类型 游戏服务器？网关 ？ 
		u16 Port; //端口号
		s32 MaxPlayer; //最大玩家数 开辟内存
		s32 MaxConnect; //最大连接数量
		u8 RCode; // 没听清 消息？
		s32 Version; // 版本号
		s32 ReceOne; // 客户端每次登陆后的缓存   是每个玩家的缓存？
		s32 ReceMax;  //最大缓存？
		s32 SendOne; //每次发送数据的缓存
		s32 SendMax; //最大发送缓存 
		s32 HeartTime; //心跳时间 验证连接是否有效
		s32 MaxAccept;  //没听太清楚
		s32 MaxRece;  // ??
		s32 MaxSend; // ??  最大发送信息数量？
		char SafeCode[20]; //加密码
		char Head[3]; //用于验证消息头规则
		char IP[MAX_IP_LEN];//IP地址
	};
	
	//客户端连接服务端时 可配置连接哪些服务器
	struct ServerListXML
	{
		s32 ID;//目标服务器ID
		u16 Port; //端口
		char IP[MAX_IP_LEN];//IP地址
	};

	//全局变量
	extern char FileExePath[MAX_EXE_LEN];
	extern ConfigXML* __ServerInfo;
	extern ConfigXML* __ClientInfo;
	extern std::vector<ServerListXML*> __ServerListInfo;
	extern void(*MD5str) ( char* output, unsigned char* input, int len );
	extern bool InitData(); //数据入口
}
#endif