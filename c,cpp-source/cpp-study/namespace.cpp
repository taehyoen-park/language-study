#include<iostream>

using namespace std;
/*
	using은 std라는 이름공간 안에 있는 함수,변수를
	모두 사용하겠다는 의미이다.
*/ 

namespace A{
	int a = 10;
}

namespace B{
	int a = 20;
}
int main()
{
	cout << "Hello, World" << endl;
	
	int a = 30;
	
	cout << a << endl; //main의 지역에 있는 a
	cout << A::a << endl; //A라는 이름공간 안에 있는 a
	cout << B::a << endl; //B라는 이름공간 안에 있는 a
	  
	return 0;
}
