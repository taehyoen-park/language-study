#include<iostream>
#include<list>
#define n 10

using namespace std;

int main()
{
	list<int>it(1); // 비어있는 리스트 선언
	list<int>it2(5); //공간이 5만큼 할당된 리스트 생성 default값은 0이다.
	list<int>it3(3,2); // 2값으로 3개가 할당된 리스트 생성
	list<int>::iterator iter;

	//앞쪽으로 원소 k를 삽입합니다. 
	it.push_front(1);
	
	//뒤쪽으로 원소 k를 삽입합니다. 
	it.push_back(2);

	/*
	출력 	 
	it.begin() 맨 앞의 원소를 가리키는 iterator를 반환합니다.
	it.end()	맨 뒤의 원소를 가리키는 iterator를 반환합니다.
	*/	
	for(iter = it.begin(); iter != it.end();iter++)
		cout << *iter << " ";
	cout << endl;
	
	
	//맨 앞의 원소를 반환,참조한다. 
	cout <<	"(맨 앞의 원소 반환).front() = " << it.front() << endl;
	
	//맨 뒤의 원소를 반환,참조 합니다. 
	cout << "(맨 뒤의 원소 반환).back() = " << it.back() << endl;
	
	//맨 마지막 원소를 제거합니다. 
	it.pop_back();
	
	//맨 앞 원소를 제거합니다.
	it.pop_front();
		
//	iter = it.begin(); 
	//iter가 가리키는 위치에 원소 k를 삽입합니다. 그 후에 iterator를 반환한다. 
	iter = it.insert(iter,100);
	cout << *(iter) << endl;
	
	//iterator가 가리키는 원소를 삭제 
//	it.erase(iter);
//	//원소의 개수를 반환합니다. 
//	it.size();
//	//k와 같은 원소를 모두 제거합니다 
//	it.remove();
//	//단항 조건자에 해당하는 원소를 모두 제거합니다. 
//	it.remove_if();
//	//원소들의 순차열을 뒤집습니다. 
//	it.reverse();
//	//모든 원소를 오름차순으로 정렬합니다. 
//	it.sort();
//	//리스트 2개를 서로 교환합니다. 
//	it.swap();
//	//인접한 원소가 같으면 유일하게 만듭니다. 
//	it.unique();
//	//2개의 리스트를 합볍 정렬합니다. default는 오름차순순 
//	it.merge();
// .assign(i,n)n으로 초기화된 i개 원소를 할당한다. 
	it.assign(3,5);
	
	 
	return 0;
}
