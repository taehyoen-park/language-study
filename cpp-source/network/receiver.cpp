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
	SOCKADDR_IN localaddr;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) return -1;

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);


	ZeroMemory(&localaddr, sizeof(localaddr));
	localaddr.sin_family = AF_INET;
	localaddr.sin_port = htons(PORT);
	localaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	retval = bind(sock, (SOCKADDR*)&localaddr, sizeof(localaddr));
	
	if (retval == SOCKET_ERROR)
	{
		printf("Socket bind : Fail(%d)", WSAGetLastError());
		return -1;
	}

	SOCKADDR_IN peeraddr;
	int addrlen;
	char buf[BUFSIZE + 1];

	while (1)
	{
		addrlen = sizeof(peeraddr);
		retval = recvfrom(sock, buf, BUFSIZE, 0, (SOCKADDR*)&peeraddr, &addrlen);
		if (retval == SOCKET_ERROR)
		{
			printf("½ÇÆÐ %d", WSAGetLastError());
			continue;
		}

		buf[retval] = '\0';
		printf("[UDP/%s:%d] %s\n", inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port),buf);
	}

	closesocket(sock);
	WSACleanup();
	return 0;

	return 0;
}