#include<iostream>

using namespace std;

namespace A{
	int a = 10;
}

namespace B{
	int a = 20;
}

int main()
{
	//A,B�� �̸� ������ �ִ� ����,�Լ��� ����ϰڴٴ� ���� 
	using namespace A;
	using namespace B;
	
	// cout << a << endl; �̸����� A,B�Ѵ� a��� ������ ������ �־� �浹�� �߻� (������ �ַ�) 
	
	cout << A::a << endl;
	cout << B::a << endl;
	// :: <-���� ������ ������ ����� ��ȣ�ߴ� a�� �̸������� �����������ν�  �浹�ذ�
	  
	return 0;	
} 
