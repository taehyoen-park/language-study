#include"Hotel.h"
#include"Guest.h"
#include<iostream>

using namespace std;

void Hotel::Set_date_Exit(int year,int month,int day){
	this->Exit_date = to_string(year)+"-"+to_string(month)+"-"+to_string(day);
}

void Hotel::Set_date_Enter(int year,int month,int day){
	this->Enter_date = to_string(year)+"-"+to_string(month)+"-"+to_string(day);
}

void Hotel::Set_std_Max_People(const int& std,const int& max){
	this->std_People = std;
	this->Max_People = max;
}

void Hotel::Add_guest(const Guest& guest){
	this->guest = guest;
	
}

Hotel::Hotel()
{
	this->Enter_date = "-";
	this->Exit_date = "-";
	this->Room_name = "-";
	this->std_People = 0;
	this->Max_People = 0;
	this->num_People = 0;
	this->price = 0;
}

void Hotel::Print_room()
{
	Guest g = this->Get_guest();
	cout << "�� �̸� :" << this->Room_name << endl;
	cout << "�� ������ :" << g.Get_name() << endl;
	cout << "�� ���ο� �� :" << g.Get_name() << "�Ը� ������ ��" << this->num_People << "��\n";
	cout << "�Խ� ��¥ :" << this->Enter_date << endl;
	cout << "��� ��¥ :" << this->Exit_date << endl;
	cout << "�� ���� :" << this->price << endl;
//	cout << "�� �̸�:" << room[i].Get_Roomname() << endl;
//	cout << "�� �̸�:" << room[i].Get_Roomname() << endl;
}

