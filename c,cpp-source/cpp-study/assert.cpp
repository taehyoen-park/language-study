#include<iostream>
#include<cassert>

using namespace std;


int main()
{
	int score;
	while(true)
	{
		cout << "input data : ";
		cin >> score;
		assert(score >= 0);  // score�� 0ũ�ų� �������� ���  
		cout << "=> score" << score << endl;	
	}
		
	
	
	
	return 0;
}
