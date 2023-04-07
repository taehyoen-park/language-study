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

	//호스트 바이트 -> 네트워크 바이트
	printf("호스트 바이트 -> 네트워크 바이트\n");
	printf("0x%x -> 0x%x\n", x, x2 = htons(x));
	printf("0x%x -> 0x%x\n", y, y2 = htonl(y));

	//네트워크 바이트 (빅 엔디언)-> 호스트 바이트
	printf("호스트 바이트 -> 네트워크 바이트\n");
	printf("0x%x -> 0x%x\n", x, x2 = ntohs(x2));
	printf("0x%x -> 0x%x\n", y, y2 = ntohl(y2));

	WSACleanup();
	return 0;
}*/