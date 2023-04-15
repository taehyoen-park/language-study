#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define commet (lib,"ws2_32.lib")
#define commet (lib,"user32.lib")
#include<winsock2.h>
#include<stdlib.h>
#include<iostream>

#define BUFSIZE 512
#define PORT 9000

int main()
{
	int retval;

	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata)) return 0;

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);

	BOOL bEnable = TRUE;
	retval = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&bEnable, sizeof(bEnable));

	if (retval == SOCKET_ERROR) {
		printf("실패", WSAGetLastError());
		return -1;
	}

	SOCKADDR_IN remoteaddr;
	ZeroMemory(&remoteaddr, sizeof(remoteaddr));
	remoteaddr.sin_family = AF_INET;
	remoteaddr.sin_port = htons(PORT);
	remoteaddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

	char buf[BUFSIZE + 1];
	int len;

	while (1)
	{
		printf("\n전송 데이터");
		if (fgets(buf, BUFSIZE + 1, stdin) == NULL) break;

		len = strlen(buf);
		if (buf[len - 1] == '\n') buf[len - 1] = '\0';
		if (strlen(buf) == 0) break;

		retval = sendto(sock, buf, strlen(buf), 0, (SOCKADDR*)&remoteaddr, sizeof(remoteaddr));
		if (retval == SOCKET_ERROR)
		{
			printf("실패 %d", WSAGetLastError());
			continue;
		}
		printf("%d byte 전송\n", retval);
	}

	closesocket(sock);
	WSACleanup();
	return 0;

	return 0;
}