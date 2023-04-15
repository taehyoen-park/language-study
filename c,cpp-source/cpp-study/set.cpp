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
	
	// set������ ��� 
	cout << "set : ";
	for(auto& v : s)
		cout << v << " ";
	cout << endl;
	
	// Ư�� ���� ã�� 
	auto it = s.find(4); // 4�� ���� ��� set�� ���κ� ��ȯ  
	if(it != s.end()) 
		cout << "found!" <<*it << endl;
	else cout << "Not found " << *it << endl;
	
	// set �� ������ ��� 
	cout << "set�� ������: " << s.size() << endl;
	
	// ������ ���� ���� 
	s.erase(3);
	cout << "set : ";
	for(auto v : s)
		cout << v << " " ;
	cout << endl;
	
	auto start = s.begin(); // set�� ���ͷ����� ��ȯ 
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
