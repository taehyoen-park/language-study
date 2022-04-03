#include<stdio.h>

int main()
{
	int i,j,temp;
	int arr[8]= {1,8,5,6,7,4,3,2};
	
	for(i = 1; i < 7; ++i){
		for(j = i; j >= 0; --j){
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
	
	for(i = 0; i < 8; ++i)
		printf("%d ",arr[i]);
		
	return 0;
 } 
