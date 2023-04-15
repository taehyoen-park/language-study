#include<iostream>

using namespace std;

template<typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	int a = 2, b = 3;
	float c = 3.4,f = 3.5;
	string str1 = "Hello" , str2 = " World";
	cout << sum(a,b) << endl;
	cout << sum(c,f) << endl;
	cout << sum(str1,str2) << endl;
	return 0;
}
