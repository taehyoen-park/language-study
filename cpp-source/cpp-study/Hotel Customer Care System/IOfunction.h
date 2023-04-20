#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Hotel.h"

using namespace std;

string room_name[8] = { "�ñ״Ͽ� �����̾� ��", //50 2 4
	"�йи� �����̾� ŷ��", //57 2 4
	"�𷰽� �����̾� ��", //62 3 5
	"�ñ״Ͽ� �𷰽� ��", //68 3 5 
	"Ʈ�� �ñ״Ͽ� ���� �𷰽� ��", //76 4 6
	"Ʈ�� �ñ״Ͽ� �����̾� ���� ��", //82 4 6 
	"�׷��� �йи�Ʈ�� �����̾� ��", //88 5 7
	"�����̾� �ñ״Ͽ� ����Ʈ �𷰽� ��" //95 5 7
	};
	
int std_max_people[8] = {2,2,3,3,4,4,5,5};	
int area[8] = {50,57,62,68,76,82,88,95};
int price[8] = {20,25,30,35,50,55,75,80};
int Point[8] = {50,100,150,200,250,300,350,400};

void Show_Hotelroom()
{
	for(int i = 1; i <= 8;i++)
	{
		printf("******************************************************\n");
		printf("%d.	�� �̸�:",i);
		cout << room_name[i-1] << endl;
		printf("	�� ����:%d��\n",area[i-1]); 
		printf("  	ǥ���ο�:%d �ִ��ο�:%d\n",std_max_people[i-1],std_max_people[i-1]+2);
		printf("	����:%d0,000 (�δ� �߰� ���:100,000)\n",price[i-1]);
		printf("	%d����Ʈ ����",Point[i-1]);
		printf("	���� ���� ����\n");
		printf("	���� ��������\n");
		printf("	������ ���� �̿�\n");
		printf("	���� �ı� ����\n");
		printf("	��� ���� �ݿ�\n");
		printf("	�ｺ�� ���� ��� ����\n");
		printf("******************************************************\n\n");
	}
}

void Choice_Room(Hotel& room,int Choice)
{
	int std = std_max_people[Choice-1];
	int max = std_max_people[Choice-1]+2;
	room.Set_std_Max_People(std,max);
	
	const string& str = room_name[Choice-1];
	room.Set_Roomname(str);
}

bool Write_member(const string& value)
{
	ofstream WriteFile;
	WriteFile.open("./Member_list/.txt");
	WriteFile.write(value);
	WriteFile.close();
}

bool Read_member(const string& name)
{
	ifstream readFile;
	readFile.open("Member_list.txt");
	
	while(readFile.is_open())
	{
		while(!readFile.eof())
		{
			string str;
			getline(readFile,str);
			if(str == name)
				return true; 
			else continue;
		}
		readFile.close();
	}
	return false;
}


