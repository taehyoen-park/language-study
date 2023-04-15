#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<winsock2.h>
#define PORT 9000
#define MAXBUF 4096

using namespace std;

int main()
{
	SOCKET clientSocket;
	SOCKADDR_IN serv_Addr;
	SOCKADDR_IN recv_Addr;
	SOCKET serv_Socket;
	WSADATA wsadata;

	int ret;
	char buf[MAXBUF];
	int size;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata)) return 0;

	//소켓을 생성한다.
	clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		printf("Socket Create : tlfvo(%d)\n", WSAGetLastError());
		return 0;
	}

	ZeroMemory(&serv_Addr, sizeof(serv_Addr));
	serv_Addr.sin_family = AF_INET;
	serv_Addr.sin_port = htons(PORT);
	serv_Addr.sin_addr.S_un.S_addr = inet_addr("172.17.209.123");
	


	while(1)
	{
		printf("전달할 데이터 :  \n");
		scanf("%s", buf);

		ret = sendto(clientSocket, buf, strlen(buf), 0,
			(struct sockaddr*)&serv_Addr, sizeof(serv_Addr));
		
		if (ret == SOCKET_ERROR)
		{
			printf("sendto error : 실패 (%d)\n", WSAGetLastError());
			closesocket(clientSocket);
			return 0;
		}
		buf[ret] = 0;
		printf("recvfrom ===> %s\n", buf);
	
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}
}