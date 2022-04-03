#include<stdio.h>
#define MAX 10

int main()
{
	int heap[10] = {10,5,8,9,6,6,8,2,4,1};
	int child,root,temp,i,j;
	
	for(i = 1; i < MAX; i++)
	{
		child = i;
		do{
			root = (child - 1) / 2;
			if(heap[root] < heap[child])
			{
				temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			child = root;
		}while(child != 0);
	}
	
	for(i = MAX - 1; i >= 0; i--)
	{
		temp = heap[i];
		heap[i] = heap[0];
		heap[0] = temp;
		root = 0;
		child = 1;
		do{
			child = 2 * root + 1;
			if(heap[child] < heap[child+1] && child < i - 1)
				child++;
			
			if(heap[root] < heap[child] && child < i)
			{
				temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			root = child;
		}while(child < i);
	}
	
	for(i = 0; i < MAX; i++)
		printf("%d ",heap[i]);
		
	return 0;
}
