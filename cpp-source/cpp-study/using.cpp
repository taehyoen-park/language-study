#include<iostream>

using namespace std;

namespace A{
	int a = 10;
}

namespace B{
	int a = 20;
}

int main()
{
	//A,B의 이름 공간에 있는 변수,함수를 사용하겠다는 선언 
	using namespace A;
	using namespace B;
	
	// cout << a << endl; 이름공간 A,B둘다 a라는 변수를 가지고 있어 충돌이 발생 (컴파일 애러) 
	
	cout << A::a << endl;
	cout << B::a << endl;
	// :: <-범위 지정자 연산을 사용해 모호했던 a의 이름공간을 지정해줌으로써  충돌해결
	  
	return 0;	
} 
