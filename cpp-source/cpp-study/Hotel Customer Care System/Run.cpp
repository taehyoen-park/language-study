#include<iostream>
//#include"Run.h"

using namespace std;
void Reservation();
void Guest_Show();
void Room_data();
bool Exit(){return false;}

void Run()
{
	bool Power = true;
	while(Power)
	{
		printf("�ؽű� ȸ�� ���Խ� ����Ʈ1,000����!\n");
		printf("�ֱ� 1�Ⱓ ���� ��������\n");
		printf("Diamod:1�� ���� 500���� �̻� ������\n");
		printf("Platinum:1�� ���� 350���� �̻� ������\n");
		printf("Gold:1�� ���� 200���� �̻� ������\n");
		printf("Silver:1�� ���� 100���� �̻� ������\n");
		printf("Classic:���� 1ȸ �̻�\n\n");
	
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		printf("�� 1. ����					  ��\n");
		printf("�� 2. ȸ�� ���					  ��\n");
		printf("�� 3. ���� ����				  	  ��\n");
		printf("�� 4. ����					  ��\n"); 
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		cout << "� �۾��� �����Ͻðڽ��ϱ�? :";
		int Choice;
		cin >> Choice;
		cin.ignore();
		switch (Choice)
		{
			case 1:
				Reservation();
				break;
			case 2:
				Guest_Show();
				break;
			case 3:
				Room_data();
				break;
			case 4:
				Power = Exit();
				break;
			default:
				cout << "���� �۾��Դϴ�." << endl;
				break; 
		}
	}
}
