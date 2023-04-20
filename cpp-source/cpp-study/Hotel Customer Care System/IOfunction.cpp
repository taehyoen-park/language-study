#include<iostream>
#include<string>
#include<vector>
#include"IOfunction.h"

extern vector<Hotel> room;

void Input()
{
	string name,country,phonenum; 
	int age,year,month,day,num_people,C;
	Guest g;Hotel h;
	
	cout << "총 인원을 입력해주세요:";
	cin >> num_people;
	h.Set_Numpeople(num_people);
	
	cout << "입실하실 날짜를 입력해주세요.ex)2022 05 01" << endl;
	cout << "날짜:";
	cin >> year >> month >> day;
	h.Set_date_Enter(year,month,day);
	
	cout << "퇴실하실 날짜를 입력해주세요.ex)2022 05 01" << endl;
	cout << "날짜:";
	cin >> year >> month >> day;
	h.Set_date_Exit(year,month,day);
	
	Show_Hotelroom();//빙 목록 공개 
	
	cout << "방을 골라주세요";
	cin >> C;
	Choice_Room(h,C);
	
	cout << "이름을 입력해주세요:"; 
	cin >> name;
	if(Read_member(name))
	{
		Read_record(name);
		
		return;
	}
	else Write_member(name);
	g.Set_name(name);
	
	cout << "나이를 입력해주세요:";
	cin >> age;
	string tem = to_string(age);
	Write_member(tem,);
	g.Set_age(age);
	
	cout << "본인의 국적을 입력해주세요:";
	cin >> country;
	Write_member(country);
	g.Set_Country(country);
	
	cout << "휴대폰 번호를 입력해주세요:";
	cin >> phonenum;
	Write_member(phonenum);
	g.Set_phoneNum(phonenum);
	
	Write_member("기록 보기");
	h.Add_guest(g);
	room.emplace_back(h);
	
	return;
}

void Output()
{
	ifstream readFile;
	readFile.open("Member_list.txt");
	
	while(readFile.is_open())
	{
		while(!readFile.eof())
		{
			string str;
			getline(readFile,str);
			cout << str << endl;
		}
		readFile.close();
	}
	return;
} 

