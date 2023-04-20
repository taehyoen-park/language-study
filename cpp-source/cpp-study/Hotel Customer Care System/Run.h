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
	cout << "1.등록하기" << endl;
	cout << "2.취소하기" << endl; 
	int Choice;
	
	cin >> Choice;
	switch(Choice)
	{
		case 1:
			Input();
			break;
		default:
			cout << "잘못입력 하셨습니다." << endl;
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
