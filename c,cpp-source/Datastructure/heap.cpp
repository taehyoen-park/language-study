#include<iostream>
#include<algorithm>
#define max 10

using namespace std;
void print_array(int arr[])
{
	for(int i = 0; i < max; i++)
		cout << arr[i] << " ";
	cout << endl;

	return;
}
void Isheap(int arr[])
{
	if(is_heap(arr,arr+10))
		cout << "힙 구조!" << endl;
	else cout << "힙 구조 실패!" << endl;
}

void Makeheap(int arr[])
{
	for(int i = 1; i < max; i++)
	{
		int c = i;
		do{
			int root = (c - 1) / 2;
			if(arr[root] < arr[c])
			{
				int temp = arr[c];
				arr[c] = arr[root];
				arr[root] = temp;
			}
			c = root;
		}while(c != 0);
	}
}
int main()
{
	int arr1[10] = {5,1,9,4,6,2,8,3,7,10};
	
	//보통 배열 
	print_array(arr1);
	Isheap(arr1);
	
	//힙 구조 만들기 
	Makeheap(arr1);
	print_array(arr1);
	Isheap(arr1); 
	
	cout << "\n";
	int arr2[10] = {15,16,18,10,12,17,19,13,14,11};
	
	//보통 배열 
	print_array(arr2);
	Isheap(arr2);
	
	//힙구조 만들기 - c++내장 함수 #include<algorithm> - make_heap() 
	make_heap(arr2,arr2+10);
	print_array(arr2);
	Isheap(arr2); 
	
	return 0;
}
