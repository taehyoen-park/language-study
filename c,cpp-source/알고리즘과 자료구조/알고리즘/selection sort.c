#include<stdio.h>

int main()
{
	int i,j,temp;
	int arr[8]= {1,8,5,6,7,4,3,2};
	 
	for(i = 0; i < 8; i++){
		for(j = i; j < 8;j++)
		{
			if(arr[i] > arr[j])
			 {
			 	temp = arr[i];
			 	arr[i] = arr[j];
			 	arr[j] = temp;
			 }
		}
	}
	
	for(i = 0; i < 8; ++i)
		printf("%d ",arr[i]);
	return 0;
}
