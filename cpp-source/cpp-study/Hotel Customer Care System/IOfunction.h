#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Hotel.h"

using namespace std;

string room_name[8] = { "시그니엘 프리미엄 룸", //50 2 4
	"패밀리 프리미엄 킹룸", //57 2 4
	"디럭스 프리미엄 룸", //62 3 5
	"시그니엘 디럭스 룸", //68 3 5 
	"트윈 시그니엘 오션 디럭스 룸", //76 4 6
	"트윈 시그니엘 프리미엄 오션 룸", //82 4 6 
	"그랜드 패밀리트윈 프리미엄 룸", //88 5 7
	"프리미엄 시그니엘 스위트 디럭스 룸" //95 5 7
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
		printf("%d.	방 이름:",i);
		cout << room_name[i-1] << endl;
		printf("	방 넓이:%d㎡\n",area[i-1]); 
		printf("  	표준인원:%d 최대인원:%d\n",std_max_people[i-1],std_max_people[i-1]+2);
		printf("	가격:%d0,000 (인당 추가 비용:100,000)\n",price[i-1]);
		printf("	%d포인트 지급",Point[i-1]);
		printf("	무료 셀프 주차\n");
		printf("	무료 와이파이\n");
		printf("	수영장 무료 이용\n");
		printf("	뷔페 식권 제공\n");
		printf("	모든 객실 금연\n");
		printf("	헬스장 무료 사용 가능\n");
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


