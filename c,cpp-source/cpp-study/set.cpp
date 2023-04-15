#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int> s;
	
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(5);
	
	// set데이터 출력 
	cout << "set : ";
	for(auto& v : s)
		cout << v << " ";
	cout << endl;
	
	// 특정 원소 찾기 
	auto it = s.find(4); // 4가 없을 경우 set의 끝부분 반환  
	if(it != s.end()) 
		cout << "found!" <<*it << endl;
	else cout << "Not found " << *it << endl;
	
	// set 의 사이즈 출력 
	cout << "set의 사이즈: " << s.size() << endl;
	
	// 지정한 원소 삭제 
	s.erase(3);
	cout << "set : ";
	for(auto v : s)
		cout << v << " " ;
	cout << endl;
	
	auto start = s.begin(); // set에 이터레이터 반환 
	auto end = s.end(); 
	s.erase(start,end);
	cout << "set : ";
	for(auto v : s) 
		cout <<  v << " ";
	cout << endl;
	
	s.insert(2);
	s.insert(10);
	s.insert(40);
	s.insert(39);
	s.insert(9);
	cout << "set : ";
	for(auto& v : s) 
		cout << v << " ";
	cout << endl;
		
	if(s.empty())
		cout << "set is empty!" << endl;
	else 
		cout << "set is not empty" << endl;
	
	s.clear();
	cout << "clear set!" << endl;
	
	if(s.empty())
		cout << "set is empty!" << endl;
	else 
		cout << "set is not empty" << endl;
	 
	return 0;
}
