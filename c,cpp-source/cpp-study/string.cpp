#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string str = "Hello";
	string str2 = ",World";
	
	cout << str << endl;
	cout << str2 << endl;
	cout << "str과 str2결합 " << str+str2 << endl;
	cout << "str == str2가? (문자열 비교)" << (str == str2) << endl; 
	cout << "str != str2가? (문자열 비교)" << (str != str2) << endl;
	
	//str.length()
	string s = "Hello, World";
	cout << "s = Hello, World, s.length() = " << s.length() << endl << endl;
	
	//str.erase()
	s.erase(0,5);
	cout << "s = Hello, World, s.erase(0,5) = " << s << endl;
	s = "Hello, World";
	/*
	s.erase(',');
	cout << "s = Hello, World, s.erase(0,5) = " << s << endl;
	s = "Hello, World";*/
	
	//str.find()
	cout << "s = Hello, world, s.find(""World"") = " << s.find("World") << "번째 부터 나온다."<< endl;
	cout << "s = Hello, world, s.find('o') = " << s.find('o') << "번째에 있다." << endl;
	cout << "s = Hello, world, s.find('W',4) = " << s.find('W',4) << "번째에 있다 #4번째 부터 시작해 W를 찾는다." << endl << endl; 
	
	//str.insert()
	s.insert(1,3,'E');
	cout <<  "s = Hello, world, s.insert(1,3,E) = " << s << endl;
	s = "Hello, world";
	
	s.insert(2,"E");
	cout <<  "s = Hello, world, s.insert(2,E) = " << s << endl;
	s = "Hello, world";
	
	s.insert(5,"HeyHey!");
	cout <<  "s = Hello, world, s.insert(5,HeyHey) = " << s << endl;
	s = "Hello, world";
	
	s.insert(6,"HeyHey!",0,4);
	cout <<  "s = Hello, world, s.insert(6,HeyHey!,0,4) = " << s << endl << endl;
	
	//s.replace()
	/*
	s.insert(0,1,'E');
	cout <<  "s = Hello, world, s.insert(0,1,E)" << s << endl;
	s.insert(0,1,'E');
	cout <<  "s = Hello, world, s.insert(0,1,E)" << s << endl;*/
	
	
	return 0;
}
