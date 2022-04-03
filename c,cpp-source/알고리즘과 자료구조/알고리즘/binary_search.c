#include<stdio.h>



int binary_search(int arr[],int start,int end,int target)
{
	while(start < end)
	{
		int middle = (start+end)/2;
		
		if(arr[middle] > target)
			end = middle;
		else if(arr[middle] < target)
			start = middle+1;
		else 
			return middle;
	}
}
int main()
{
	int i,n;
	int arr[101];
	for(i = 1; i <= 100 ;i++)
		arr[i] = i;
	scanf("%d",&n);
	
	printf("%d",binary_search(arr,0,100,n));
	return 0;
} 
