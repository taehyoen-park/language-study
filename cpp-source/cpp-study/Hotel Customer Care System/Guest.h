#pragma once
#include<string>
using namespace std;

class Guest{
private:
	string name,Country,Record;
	string Membership_rating,phoneNum;
	int age,point;
public:
	void Set_Country(string Country){ this->Country = Country;}
	void Set_name(string name){ this->name = name;}
	void Set_age(int age){this->age = age;}
	void Set_phoneNum(string phoneNum){this->phoneNum = phoneNum;}
	void Add_Record(string Record);
	string Get_Country()const{ return this->Country;}
	string Get_name()const{ return this->name;}
	int Get_age()const{return this->age;}
	string Get_Membership_rating()const{ return this->Membership_rating;}
	string Get_phoneNum()const{ return this->phoneNum;}
	int Get_point()const{return this->point;}
	void print_Guest()const;
	void operator=(const Guest& guest);
	Guest();
};

//c,s,g,p,d
