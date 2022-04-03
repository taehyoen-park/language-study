#include<stdio.h>
#include<stdbool.h>
#define MAX 10

bool Check[MAX];
bool link[MAX][MAX];

typedef struct Queue{
	int front,rear;
	int data[MAX];
}queue;

void BFS(int start)
{
	int cur,i;
	queue q;
	
	q.front = 0;
	q.rear = 0;
	
	q.data[q.rear++] = start;
	Check[start] = true;
	
	while(q.rear > q.front)
	{
		cur = q.data[q.front++];
		printf("%d ",cur);
		for(i = 1; i <= 9; i++)
		{
			if(link[cur][i])
			{	
				if(!Check[i])
				{
					Check[i] = true;
					q.data[q.rear++] = i;
				}
			}	
		}
	}
}
int main()
{
	link[1][2] = true;
	link[1][3] = true;
	link[1][8] = true;
	link[2][4] = true;
	link[2][5] = true;
	link[3][6] = true;
	link[3][7] = true;
	link[1][8] = true;
	link[8][9] = true;
	BFS(1);
	
	return 0;
}
