#pragma comment (lib , "ws2_32.lib")

/*#include<WinSock2.h>
#include<stdio.h>

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return -1;

	short x = 40000;
	u_long y = 0x12345678;
	short x2;
	u_long y2;

	//ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ
	printf("ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ\n");
	printf("0x%x -> 0x%x\n", x, x2 = htons(x));
	printf("0x%x -> 0x%x\n", y, y2 = htonl(y));

	//��Ʈ��ũ ����Ʈ (�� �����)-> ȣ��Ʈ ����Ʈ
	printf("ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ\n");
	printf("0x%x -> 0x%x\n", x, x2 = ntohs(x2));
	printf("0x%x -> 0x%x\n", y, y2 = ntohl(y2));

	WSACleanup();
	return 0;
}*/