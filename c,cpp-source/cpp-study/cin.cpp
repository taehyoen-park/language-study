#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a,b;
	cout << "1.���� �Է�" << endl; 
	cout << "����a�� �Է��Ͻÿ�:";
	cin >> a;
	cout << "����b�� �Է��Ͻÿ�:";
	cin >> b;
	cout << "a+b��" << a+b << "�Դϴ�." << endl << endl;
	
	string str;
	cout << "2.���ڿ� �Է�" << endl;
	cout << "str�� ���� ���ڿ��� �Է��Ͻÿ�" << endl;
	cin >> str;
	cout << "str��" << str << "�Դϴ�." << endl << endl;; 
 
	cout << "getlin()�� ���ڿ� �Է¹ޱ�" << endl;
	string name;
	cout << "�̸��� �����ΰ���?" << endl;
	cin.ignore();
	getline(cin,name);
	cout << name << endl << endl;
	
	cout << "getline(cin,string)�� ���鹮�ڵ� ���� �д´� ������ �� ������ ���鹮�ڸ�";
	cout << " ��Ʈ���� ���ܳ����� �װ� �о���̱� ������ cin.ignore()�Լ��� ����ؾ��Ѵ�.";
	return 0;
}
