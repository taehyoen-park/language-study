#include<iostream>

using namespace std;
/*
	using�� std��� �̸����� �ȿ� �ִ� �Լ�,������
	��� ����ϰڴٴ� �ǹ��̴�.
*/ 

namespace A{
	int a = 10;
}

namespace B{
	int a = 20;
}
int main()
{
	cout << "Hello, World" << endl;
	
	int a = 30;
	
	cout << a << endl; //main�� ������ �ִ� a
	cout << A::a << endl; //A��� �̸����� �ȿ� �ִ� a
	cout << B::a << endl; //B��� �̸����� �ȿ� �ִ� a
	  
	return 0;
}
