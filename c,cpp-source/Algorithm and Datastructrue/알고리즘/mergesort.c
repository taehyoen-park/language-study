#include<stdio.h>


int num[8];
void merge(int arr[],int start,int middle,int end)
{
	int i = start;
	int j = middle+1;
	int k = start;
	int t;
	
	while(i <= middle && j <= end)
	{
		if(arr[i] <= arr[j])
		{
			num[k] = arr[i];
			i++;
		}
		else
		{
			num[k] = arr[j];
			j++;
		}
		k++;
	}
	if(i > middle)
	{
		for(t = j; t < end; t++)
		{
			num[k] = arr[t];
			k++;
		}
	}
	else
	{
		for(t = i; t < end; t++)
		{
			num[k] = arr[t];
			k++;
		}
	}
	
	for(t = start; t < end; t++)
		arr[t] = num[t];
}

void mergesort(int a[], int start,int end)
{
	if(start < end)
	{
		int middle = (start+end)/2;
		mergesort(a,start,middle);
		mergesort(a,middle+1,end);
		merge(a,start,middle,end);
	}
}
int main()
{
	int arr[8] = {5,3,6,2,4,7,1,8};
	int i;
	
	mergesort(arr,0,7);
	for(i = 0; i < 8; i++)
		printf("%d ",arr[i]);
	return 0;
}
