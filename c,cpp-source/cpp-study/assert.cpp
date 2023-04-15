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
		assert(score >= 0);  // score가 0크거나 같을때만 통과  
		cout << "=> score" << score << endl;	
	}
		
	
	
	
	return 0;
}
