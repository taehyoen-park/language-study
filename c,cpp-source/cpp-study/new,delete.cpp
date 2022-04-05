#include<iostream>

using namespace std;

int main()
{
	int *p = new int; // int형 동적할당. 
	
	*p = 10;
	cout << *p << endl;
	
	int *arr = new int[10]; //배열 동적할당 
	for(int i = 0; i < 10; i++)
		arr[i] = i+1;
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " "; 
	
	delete p; // 동적할당 해제 
	delete arr;
	return 0;
}
