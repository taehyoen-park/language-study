#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a,b;
	cout << "1.숫자 입력" << endl; 
	cout << "정수a를 입력하시오:";
	cin >> a;
	cout << "정수b를 입력하시오:";
	cin >> b;
	cout << "a+b는" << a+b << "입니다." << endl << endl;
	
	string str;
	cout << "2.문자열 입력" << endl;
	cout << "str에 넣을 문자열을 입력하시오" << endl;
	cin >> str;
	cout << "str은" << str << "입니다." << endl << endl;; 
 
	cout << "getlin()로 문자열 입력받기" << endl;
	string name;
	cout << "이름이 무엇인가요?" << endl;
	cin.ignore();
	getline(cin,name);
	cout << name << endl << endl;
	
	cout << "getline(cin,string)은 공백문자도 전부 읽는다 하지만 그 이전에 공백문자를";
	cout << " 스트림을 남겨놓으면 그걸 읽어들이기 때문에 cin.ignore()함수를 사용해야한다.";
	return 0;
}
