/*#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib,"ws2_32.lib")
#include<Winsock2.h>
#include<stdio.h>

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(1, 1), &wsa) != 0)return -1;

	//IP주소 입력
	char *servIP = (char*)"192.168.35.115";
	printf("IP주소 = %s\n", servIP);

	//inet_addr() 함수
	printf("IP 변환주소 = 0x%x\n", inet_addr(servIP));

	//inet_ntoa() 함수
	IN_ADDR temp;
	temp.S_un.S_addr = inet_addr(servIP);
	printf("IP 변환주소 = %s\n", inet_ntoa(temp));

	//윈속 종료
	WSACleanup();
	return 0;


}*/