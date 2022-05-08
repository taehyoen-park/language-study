#include<iostream>

using namespace std;

int INF = 1000000000;
int arr[4][4] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0},
};

void FloydWarshall(){
	int num[4][4];
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			num[i][j] = arr[i][j];
		}
	}
	
	for(int k = 0; k < 4; k++){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4;j++){
				if(k == i)
					break;
				if(num[i][k]+num[k][j] < num[i][j]){
					num[i][j] = num[i][k]+num[k][j];
				}
				else 
					continue;
			}
		}
	}
	
	for(int i = 0 ; i < 4; i++){
		for(int j = 0 ;j < 4; j++){
			cout << num[i][j] << " ";
		}
		cout <<"\n";
	}
}
int main()
{
	FloydWarshall();
	return 0;
 } 
