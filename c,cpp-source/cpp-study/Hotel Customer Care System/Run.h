#pragma once
#include"Guest.h"
#include"Hotel.h"
#include"IOfunction.h"
#include<vector>
#include<iostream>

vector<Hotel> room;

//void Input();
void Run();
void Reservation()
{
	cout << "1.����ϱ�" << endl;
	cout << "2.����ϱ�" << endl; 
	int Choice;
	
	cin >> Choice;
	switch(Choice)
	{
		case 1:
			Input();
			break;
		default:
			cout << "�߸��Է� �ϼ̽��ϴ�." << endl;
			break;
	}
}

void Guest_Show(){
	Output();
}

void Room_data()
{
	for(int i = 0; i < room.size();i++)
	{
		room[i].Print_room();
		cout << endl;
	}	
}
