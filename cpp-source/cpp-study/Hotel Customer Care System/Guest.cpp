#include"Guest.h"
#include<iostream>
using namespace std;

void Guest::print_Guest()const
{
	cout << this->name << endl;
	cout << this->age << endl;
	cout << this->Country << endl;
	cout << this->point << endl;
	cout << this->Membership_rating << endl;
	cout << this->phoneNum << endl;
}

void Guest::operator=(const Guest& guest)
{
	this->name = guest.Get_name();
	this->age = guest.Get_age();
	this->Country = guest.Get_Country();
	this->point = guest.Get_point();
	this->Membership_rating = guest.Get_Membership_rating();
	this->phoneNum = guest.Get_phoneNum();
}

void Guest::Add_Record()
{
	
}

Guest::Guest()
{
	this->name = "-";
	this->age = 0;
	this->Country = "-";
	this->point = 0;
	this->Membership_rating = "-";
	this->phoneNum = "-";
}


