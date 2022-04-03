#include<stdio.h>

void quicksort(int arr[],int start,int end)
{
	if(start >= end)
		return;
		
	int pivot = start;
	int i = start+1;
	int j = end;
	int temp;
	
	while(i <= j)
	{
		while(arr[i] <= arr[pivot] && i <= end){
			i++;
		}
		
		while(arr[j] >= arr[pivot] && j > start){
			j--;
		}
		
		if(i > j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	quicksort(arr,start,j-1);
	quicksort(arr,j+1,end);
}

int main()
{
	int i;
	int arr[8]= {2,7,5,6,8,4,3,1};
	quicksort(arr,0,7);
	
	for(i = 0; i < 8; i++)
		printf("%d ",arr[i]);
		
	return 0;
}
