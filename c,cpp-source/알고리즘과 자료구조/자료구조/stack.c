#include<stdio.h>

int stack[100];
int cursur = -1;

void push(int a)
{
	cursur++;
	stack[cursur] = a;
}

void pop()
{
	cursur--;
}

int top()
{
	return stack[cursur];
}

int empty()
{
	if(cursur == -1)
		return 1;
	else
		return 0;
}

int size()
{
	return (cursur+1);
}

int main()
{
	push(5);
	push(6);
	push(8);
	pop();
	push(9);
	push(10);
	pop();
	
	printf("%d\n",size());
	
	while(!empty())
	{
		printf("%d ",top());
		pop();
	}

	return 0;
}
