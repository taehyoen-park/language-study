#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<int>v;//���� ���� 
	vector<int>::iterator iter; // ������ �ݺ��� ���� 
	
	list<int>it; //����Ʈ ����  
	list<int>::iterator iter2;//����Ʈ �ݺ��� ���� 
	
	iter = v.begin();
	//���� ���� 
	cout <<	*(iter+2) << endl;
	//[]���� ���� ���� ���� 
	cout << iter[5] << endl; 
	
	for(int i = 0 ;i < 10; i++)
		v.push_back(i+1);
	for(iter = v.begin();iter < v.end();iter++)
		cout << *iter << " ";
	cout << endl;
	
	 
	
	
	
	
		
	return 0;
}
