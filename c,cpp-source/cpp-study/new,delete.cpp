#include<iostream>

using namespace std;

int main()
{
	int *p = new int; // int�� �����Ҵ�. 
	
	*p = 10;
	cout << *p << endl;
	
	int *arr = new int[10]; //�迭 �����Ҵ� 
	for(int i = 0; i < 10; i++)
		arr[i] = i+1;
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " "; 
	
	delete p; // �����Ҵ� ���� 
	delete arr;
	return 0;
}
