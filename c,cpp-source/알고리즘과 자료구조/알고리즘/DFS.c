#include<stdio.h>
#include<stdbool.h>
#define MAX 10

bool Check[MAX];
bool link[MAX][MAX];

void DFS(int start)
{
	int i;
	Check[start] = true;
	printf("%d ",start);
	
	for(i = 1; i <= 9;i++)
	{
		if(link[start][i])
		{
			if(!Check[i])
			{
				Check[i] = true;
				DFS(i);
			}
		}
		else
			continue;
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
	DFS(1);
	return 0;
}
