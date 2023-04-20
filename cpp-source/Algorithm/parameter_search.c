#include<stdio.h>

int Lower_bound(int arr[],int start,int end,int target)
{
	while(end > start)
	{
		int middle = (start+end)/2;
		
		if(arr[middle] > target)
			end = middle;
		else
			start = middle+1;
	}
	return end;
}

int Upper_bound(int arr[],int start,int end,int target)
{
		while(end > start)
	{
		int middle = (start+end)/2;
		
		if(arr[middle] >= target)
			end = middle;
		else
			start = middle+1;
	}
	return end;
	
}

int main()
{
	int arr[15] = {-5, -5, 2, 2, 2, 6, 6, 8, 9, 10, 10, 12, 12, 15, 15};
	int i,Upper,Lower;
	
	for(i = 0; i < 15; i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("--------------���� ���----------------\n");  
	for(i = 0; i < 15; i++)
	{
		Upper = Upper_bound(arr,0,15,arr[i]);
		Lower = Lower_bound(arr,0,15,arr[i]);
		printf("%d = %d��°���� ",arr[i],Upper);
		printf("%d��° ��������= %d��\n",Lower,Lower-Upper);
	}
	return 0;
}
