#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	cout << a << endl; // main의 지역변수 a 출력; 
	
	
	int &ref_a = a;//참조자 선언(reference)
	cout << ref_a << endl; //ref_a 출력 
	/* 
	ref_a는 a의 참조자이다 이말은 a의 또다른 이름이라는 뜻이다.
	ref_a로 어떤 작업을 수행하든 a로 수행하는 것과 똑같다.
	ref_a는 메모리에 공간이 생기지 않는다 a의 다른 이름일 뿐이다.
	*/
	a += 10;
	cout << a << endl; // 20
	
	ref_a += 10;
	cout << ref_a << endl;//30;
	
 	int b = 20;
 	/*
	int ref_b; <- 컴파일 애러 발생 reference는 변수의 다른이름이다.
	선언할때 변수를 초기화 하지 않으면 변수는 없는데 이름만 달려있는 것이다.
	이를 댕글링 레퍼런스라고 한다.
	*/
	int c[10];
	int (&ref_c)[10] = c; //reference배열
	
	for(int i = 0; i < 10; i++)
		c[i] = i+1;
	
	for(int i = 0; i < 10; i++)
		cout << ref_c[i] << " ";  // 배열 출력 
	
	int d = 10;
	//int &ref_d = fuc(d); 애러
	/*
	참조자를 반환하는 함수는 변수가 그 함수가 끝날때 사라지기 때문에
	이름만 남게된다. (댕글링 레퍼런스)
	*/
	 
	return 0;
} 
