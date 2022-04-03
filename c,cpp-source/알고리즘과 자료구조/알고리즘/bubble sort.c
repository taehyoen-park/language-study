#include<stdio.h>

int main()
{
	int i,j,temp;
	int arr[8]= {1,8,5,6,7,4,3,2};
	
	//오름차순 
	for(i = 0; i < 8; i++){
		for(j = 0; j < 7;j++)
		{
			if(arr[j] > arr[j+1])
			 {
			 	temp = arr[j];
			 	arr[j] = arr[j+1];
			 	arr[j+1] = temp;
			 }
		}
	}
	
	for(i = 0; i < 8; ++i)
		printf("%d ",arr[i]);
	return 0;
}
