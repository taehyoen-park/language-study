#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *link;
}node;

typedef struct Queuelist{
	node* head;
	node* back;
}queuelist;

node* createnode(int x)
{
	node* newdata = (node*)malloc(sizeof(node*));
	newdata->data = x;
	newdata->link = NULL;
	return newdata;
}

void enqueue(queuelist *q,node* a)
{
	if(q->head == NULL)
	{
		q->head = a;
		a->link = NULL;
		q->back = a;
	}
	
	else
	{
		q->back->link = a;
		q->back = a;
	}
		
	
}

void dequeue(queuelist *q)
{
	node* temp;
	temp = q->head;
	
	if(q->head == NULL)
		return;
	else
	{
		q->head = q->head->link;
		free(temp);
	}
}

int main()
{
	int i,n;
	queuelist *A = (queuelist*)malloc(sizeof(queuelist));
	A->head = NULL;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		enqueue(A,createnode(i+1));
	
	while(A->head->link != NULL)
	{
		dequeue(A);
		enqueue(A,createnode(A->head->data));
		dequeue(A);
	}
	printf("%d",A->head->data);

	return 0;
}
