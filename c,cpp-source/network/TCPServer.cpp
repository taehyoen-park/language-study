#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#include<winsock2.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define BUFSIZE 1000
#define PORT 9000
bool Power = true;
int main()
{
	int retval;
	SOCKET listenSocket;
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return -1;

	SOCKADDR_IN servAddr;
	ZeroMemory(&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(PORT);
	servAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	if (bind(listenSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		closesocket(listenSocket);
		return -1;
	}
	
	retval = listen(listenSocket, SOMAXCONN);
	if (retval == SOCKET_ERROR)
		printf("listen() Error");

	SOCKET clientSocket;
	SOCKADDR_IN clientAddr;

	int length;
	char buf[BUFSIZE + 1];

	while (Power)
	{
		length = sizeof(clientAddr);
		clientSocket = accept(listenSocket, (SOCKADDR*)&clientAddr, &length);


		if (clientSocket == INVALID_SOCKET)
		{
			printf("accept() Error");
			continue;
		}
		
		printf("\n[TCP server]클라이언트 IP 주소 = %s, Port = %d\n",
			inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
		
		while (1)
		{
			retval = recv(clientSocket, buf, BUFSIZE, 0);
			if (retval == SOCKET_ERROR)
			{
				printf("recv() Error");
				break;
			}

			else if (retval == 0)
				break;

			buf[retval] = '\0';
			printf("TCP %s : %d %s\n", inet_ntoa(clientAddr.sin_addr),
				ntohs(clientAddr.sin_port), buf);

			// 클라이언트로부터 받은 메시지 체크
			if (strcmp(buf, "quit") == 0) {
				printf("Quit 메세지를 받았습니다. 서버를 닫습니다.\n");
				Power = false;
				break;
			}

			retval = send(clientSocket, buf, retval, 0);
			if (retval == SOCKET_ERROR)
			{
				printf("send() Error");
				break;
			}
		}
	}

	closesocket(clientSocket);
	printf("TCP server 클라이언트 종료 : IP 주소 = %s Port = %d\n",
		inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
	WSACleanup();
	return 0;
	
}