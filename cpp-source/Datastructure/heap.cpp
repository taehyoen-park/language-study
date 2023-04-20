#include<iostream>
#include<vector>

using namespace std;

class Heap{
	vector<int> arr;
};

void print_array(int arr[])
{
	for(int i = 0; i < max; i++)
		cout << arr[i] << " ";
	cout << endl;

	return;
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
	

	
	return 0;
}
