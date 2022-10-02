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


//��������û��� ��Ϊ����Ԥ����ķ�ʽ �����û�������ID���л���
#define MAX_USER_SOCKETFD 1000000

//����·���ַ�������󳤶�
#define MAX_EXE_LEN  200

//�ļ�����󳤶�
#define MAX_FILENAME_LEN 250

//�������ĺ궨��
#define SIO_KEEPALIVE_VALS IOC_IN | IOC_VENDOR | 4

//  MD5��֤ʱ����󳤶�
#define MAX_MD5_LEN  35

//IP��ַ����󳤶�
#define MAX_IP_LEN 20

//��ӡ��ʽЭ��
#define LOG_MSG printf

typedef signed char				s8;
typedef signed short				s16;
typedef signed int					s32;
typedef signed long long 		s64;
typedef unsigned char			u8;
typedef unsigned short			u16;
typedef unsigned int				u32;
typedef unsigned long long	u64;

//����һЩSocket״̬
namespace func {
	//socket�ر�ԭ��
	enum SOCKET_CLOSE
	{
		S_CLOSE_FREE = 0,
		S_CLOSE_ACCPET = 1,
		S_CLOSE_SHUTDOWN = 2,
		S_CLOSE_CLOSE = 3
	};

	//socket�����״̬
	enum SOCKET_CONTEXT_STATE
	{
		SC_WAIT_ACCEPT = 0,
		SC_WAIT_RECV = 1,
		SC_WAIT_SEND = 2,
		SC_WAIT_RESET = 3
	};

	//socket�ͻ�������״̬
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
		s32 ID; //��ǰӦ�ó���ID
		u8 Type; //��ǰӦ�ó�������� ��Ϸ������������ �� 
		u16 Port; //�˿ں�
		s32 MaxPlayer; //�������� �����ڴ�
		s32 MaxConnect; //�����������
		u8 RCode; // û���� ��Ϣ��
		s32 Version; // �汾��
		s32 ReceOne; // �ͻ���ÿ�ε�½��Ļ���   ��ÿ����ҵĻ��棿
		s32 ReceMax;  //��󻺴棿
		s32 SendOne; //ÿ�η������ݵĻ���
		s32 SendMax; //����ͻ��� 
		s32 HeartTime; //����ʱ�� ��֤�����Ƿ���Ч
		s32 MaxAccept;  //û��̫���
		s32 MaxRece;  // ??
		s32 MaxSend; // ??  �������Ϣ������
		char SafeCode[20]; //������
		char Head[3]; //������֤��Ϣͷ����
		char IP[MAX_IP_LEN];//IP��ַ
	};
	
	//�ͻ������ӷ����ʱ ������������Щ������
	struct ServerListXML
	{
		s32 ID;//Ŀ�������ID
		u16 Port; //�˿�
		char IP[MAX_IP_LEN];//IP��ַ
	};

	//ȫ�ֱ���
	extern char FileExePath[MAX_EXE_LEN];
	extern ConfigXML* __ServerInfo;
	extern ConfigXML* __ClientInfo;
	extern std::vector<ServerListXML*> __ServerListInfo;
	extern void(*MD5str) ( char* output, unsigned char* input, int len );
	extern bool InitData(); //�������
}
#endif