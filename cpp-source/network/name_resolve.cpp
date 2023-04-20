#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<Winsock2.h>
#include<stdlib.h>
#include<stdio.h>

//������ �̸� -> IP �ּ�
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

	//������ �̸� -> IP�ּ�

	IN_ADDR addr;
	if (GetIPAddr((char*)"naver.com", &addr))
	{
		//����
		printf("IP�ּ� = %s\n", inet_ntoa(addr));

		//IP�ּ� -> ������ �̸�
		char name[256];
		if (GetDomain(addr, name))
		{
			//���� 
			printf("������ �̸� = %s\n", name);
		}
	}
	WSACleanup();
	return 0;
}
