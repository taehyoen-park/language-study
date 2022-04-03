#include<stdio.h>
#include<stdbool.h>
#define MAX 100000
int number[100001];

void PrimeNumber()
{
	int i,j;
	for(i = 2 ;i <= MAX; i++)
	{
		if(number[i] == 0)
			continue;
		for(j = i + i;j <= MAX; j += i)
			number[j] = 0;
	}
}

void Print()
{
	int i;
	for(i = 2; i <= MAX; i++){
		if(number[i] != 0)
			printf("%d ",number[i]);
	}
	printf("\n");
	return;
}
int main()
{
	int i,j;
	
	for(i = 1; i <= MAX; i++)
		number[i] = i;
	
	PrimeNumber();
	Print();

	return 0;
}
