#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<Winsock2.h>
#include<stdlib.h>
#include<stdio.h>

//도메인 이름 -> IP 주소
BOOL GetIPAddr(char* name, IN_ADDR* addr)
{
	HOSTENT* ptr = gethostbyname(name);
	if (ptr == NULL) {
		return FALSE;
	}
	memcpy(addr, ptr->h_addr, ptr->h_length);
	return TRUE;
}

BOOL GetDomain(IN_ADDR addr, char* name)
{
	HOSTENT* ptr = gethostbyaddr((char*)&addr, sizeof(addr), AF_INET);
	if (ptr == NULL)return FALSE;
	strcpy(name, ptr->h_name);
	return TRUE;
}

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return -1;
	}

	//도메인 이름 -> IP주소

	IN_ADDR addr;
	if (GetIPAddr((char*)"naver.com", &addr))
	{
		//성공
		printf("IP주소 = %s\n", inet_ntoa(addr));

		//IP주소 -> 도메인 이름
		char name[256];
		if (GetDomain(addr, name))
		{
			//성공 
			printf("도메인 이름 = %s\n", name);
		}
	}
	WSACleanup();
	return 0;
}
