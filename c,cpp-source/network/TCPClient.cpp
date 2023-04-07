#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#include<winsock2.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

#define BUFSIZE 1000
#define PORT 9000

int main()
{
	int recval;
	SOCKET clientSocket;
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		printf("WSAStartup Error\n");

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
		printf("socket () Error\n");

	SOCKADDR_IN clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(PORT);
	string IPaddress;
	cout << "IP주소를 입력해주세요: ";
	cin >> IPaddress;
	getchar();
	clientAddr.sin_addr.S_un.S_addr = inet_addr(IPaddress.c_str());

	recval = connect(clientSocket, (SOCKADDR*)&clientAddr, sizeof(clientAddr));
	if (recval == SOCKET_ERROR)
		printf("connect()");

	char readBuffer[BUFSIZE + 1] = "Hello";
	int length;
	while (strcmp(readBuffer,"bye")!= 0)
	{
		ZeroMemory(readBuffer, sizeof(readBuffer));
		printf("\n[전송데이터] : ");

		if (fgets(readBuffer, BUFSIZE + 1, stdin) == NULL)
			break;

		length = strlen(readBuffer);
		if (readBuffer[length - 1] == '\n');
			readBuffer[length - 1] = '\0';
		if (strlen(readBuffer) == 0)
				break;

		recval = send(clientSocket, readBuffer, strlen(readBuffer),0);

		if (recval == SOCKET_ERROR)
		{
			printf("send()");
			break;
		}

		printf("[TCP클라이언트] %d 바이트를 보냈습니다.\n", recval);

		recval = recv(clientSocket, readBuffer, recval, 0);
		if (recval == 0)
			break;

		readBuffer[BUFSIZE] = '\0';
		printf("[TCP클라이언트] %d 바이트를 받았습니다.\n", recval);
		printf("[받은 데이터] %s.\n",readBuffer);
	}


	closesocket(clientSocket);
	WSACleanup();
	return 0;

}