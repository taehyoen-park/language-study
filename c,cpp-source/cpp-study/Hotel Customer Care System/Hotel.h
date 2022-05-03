#pragma once
#include"Guest.h"

using namespace std;

class Hotel{
private:
	string Enter_date,Exit_date,Room_name;
	int std_People,Max_People,num_People,price;
	Guest guest;
public:
	void Set_date_Enter(int year,int month,int day);
	void Set_date_Exit(int year,int month,int day);
	void Set_Numpeople(const int& num){this->num_People = num;};
	void set_Price(int price){this->price = price;}
	void Set_std_Max_People(const int& std,const int& max);
	void Set_Roomname(string Roomname){this->Room_name = Roomname;};
	
	string Get_Roomname(){return this->Room_name;}
	string Get_date_Enter(){return this->Enter_date;}
	string Get_date_Exit(){return this->Exit_date;}
	int Get_Numpeople(){return this->num_People;}
	int Get_Price(){return this->price;}
	int Get_std_People(){return this->std_People;}
	int Get_Max_People(){return this->Max_People;}
	void Add_guest(const Guest& guest);
	void Print_room();
	void plus_price(); 
	Guest& Get_guest(){return this->guest;}
	Hotel();	
};
