#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int>v; //백터선언
	vector<int>v1(3); // 3의 공간 동적할당 전부 0으로 초기화
	vector<int>v2(3,10);//3의 공간 동적할당후 전부 10으로 초기화
	vector<int>v3 = {10,20,30};//3의 공간 동적할당후 10,20,30으로 초기화
	vector<int>::iterator iter;//반복자 iterator 
	vector<int>v4[] = {{1,2},{5,7}};
	
	
	//.reserve을 통해 미리 100만큼 동적할당 
	v.reserve(100);
	
	//.size() 백터의 크기를 반환한다.
	// .capacity()할당된 공간의 크기를 반환한다. 
	cout << "v의 사이즈는 " << v.size() << "입니다." << endl;
	cout << "v1의 사이즈는 " << v1.size() << "입니다." << endl;
	cout << "v2의 사이즈는 " << v2.size() << "입니다." << endl;
	cout << "v3의 사이즈는 " << v3.size() << "입니다." << endl;
	cout << "v4의 사이즈는 " << v4[0].size() << "입니다." << endl;
	cout << "v1의 할당된 공간은 " << v1.capacity() << endl << endl; 
	
	//.push_back(n) 백터의 마지막 공간에 n을 할당 
	v.push_back(10);
	v.push_back(20);
	cout << "v의 크기" << v.size() << endl;
	
	//.at(i),[i]  i번째 요소에 접근 at는 범위를 검사하여 범위를 나가면 예외처리를 한다. 
	cout << "v의 0번째 원소" << v.at(0) << " v의 1번째 원소" << v[1] << endl; 
	
	//.pop_back() 백터의 마지막 공간의 원소 제거
	cout << "v를 pop_back()으로 원소 제거" << endl; 
	v.pop_back();
	v.pop_back();
	cout << "v의 크기" << v.size() << endl << endl;

	cout << "v백터에 10~80까지 할당 그리고 출력" << endl; 
	for(int i = 0; i < 8; i++)
		v.push_back((i+1)*10);
	for(int i = 0 ;i < 8; i++)
		cout << v[i] << " ";
	cout << endl;
	
	//.insert(i,n) i번째에 n값을 삽입한다. 혹은 insert(i,x,n) x개의 n값을 넣을 수 있다. 
	v.insert(v.begin()+3,100);
	cout << v[3] << endl; 
	v.insert(v.begin()+5,5,3);
	for(int i = 0; i < 14; i++)
		cout << v[i] << " ";
	cout << endl;
	
	//.cmpty() 백터가 비어있는지 확인한다.
	if(!v.empty())
		cout << "비어있지 않다." << endl;
	else
		cout << "비어있다."  << endl;
	
	//.erase(i) , .erase(i,j) i번만 혹은 i에서j번가지 원소를 제거합니다.
	v.erase(v.begin()+5,v.begin()+9);
	cout << "erase함수로 5에서9번째까지 원소 제거" << endl;
	for(int i = 0 ;i < 10; i++)
		cout << v[i] << " ";
	cout << endl;
	
	// .swap를 사용해 v와 v1을 바꾼다 
	v.swap(v1);
	
	
	iter = v1.begin();
	cout << *iter << endl; // 임의 접근 
	for(iter = v1.begin(); iter < v1.end();iter++)
		cout << *iter << " ";
		
	// .clear를 사용해 v의 원소를 다지운다
	v.clear();
	cout << v.size() << endl; 

	return 0;
}
