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
	
	cout << "�� �ο��� �Է����ּ���:";
	cin >> num_people;
	h.Set_Numpeople(num_people);
	
	cout << "�Խ��Ͻ� ��¥�� �Է����ּ���.ex)2022 05 01" << endl;
	cout << "��¥:";
	cin >> year >> month >> day;
	h.Set_date_Enter(year,month,day);
	
	cout << "����Ͻ� ��¥�� �Է����ּ���.ex)2022 05 01" << endl;
	cout << "��¥:";
	cin >> year >> month >> day;
	h.Set_date_Exit(year,month,day);
	
	Show_Hotelroom();//�� ��� ���� 
	
	cout << "���� ����ּ���";
	cin >> C;
	Choice_Room(h,C);
	
	cout << "�̸��� �Է����ּ���:"; 
	cin >> name;
	if(Read_member(name))
	{
		Read_record(name);
		
		return;
	}
	else Write_member(name);
	g.Set_name(name);
	
	cout << "���̸� �Է����ּ���:";
	cin >> age;
	string tem = to_string(age);
	Write_member(tem,);
	g.Set_age(age);
	
	cout << "������ ������ �Է����ּ���:";
	cin >> country;
	Write_member(country);
	g.Set_Country(country);
	
	cout << "�޴��� ��ȣ�� �Է����ּ���:";
	cin >> phonenum;
	Write_member(phonenum);
	g.Set_phoneNum(phonenum);
	
	Write_member("��� ����");
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

