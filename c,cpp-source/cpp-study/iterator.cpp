#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<int>v;//백터 선언 
	vector<int>::iterator iter; // 백터의 반복자 선언 
	
	list<int>it; //리스트 선언  
	list<int>::iterator iter2;//리스트 반복자 선언 
	
	iter = v.begin();
	//연산 가능 
	cout <<	*(iter+2) << endl;
	//[]통해 임의 접근 가능 
	cout << iter[5] << endl; 
	
	for(int i = 0 ;i < 10; i++)
		v.push_back(i+1);
	for(iter = v.begin();iter < v.end();iter++)
		cout << *iter << " ";
	cout << endl;
	
	 
	
	
	
	
		
	return 0;
}
