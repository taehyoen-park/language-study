/*#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib,"ws2_32.lib")
#include<Winsock2.h>
#include<stdio.h>

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(1, 1), &wsa) != 0)return -1;

	//IP�ּ� �Է�
	char *servIP = (char*)"192.168.35.115";
	printf("IP�ּ� = %s\n", servIP);

	//inet_addr() �Լ�
	printf("IP ��ȯ�ּ� = 0x%x\n", inet_addr(servIP));

	//inet_ntoa() �Լ�
	IN_ADDR temp;
	temp.S_un.S_addr = inet_addr(servIP);
	printf("IP ��ȯ�ּ� = %s\n", inet_ntoa(temp));

	//���� ����
	WSACleanup();
	return 0;


}*/