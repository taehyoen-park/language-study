#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUENODE{
	int data;
	struct QUEUENODE *pre;
}node;

typedef struct QUEUE{
	struct QUEUENODE *head;
}queue;

//큐를 생성한다. 
queue* createqueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->head = NULL;
	return q;
}

//노드를 집어넣는다. 
void push(queue *q,int x)
{
	node* newnode = (node*)malloc(sizeof(node));
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	newnode->data = x;
	
	if(q->head == NULL)
	{
		q->head = newnode;
		newnode->pre = NULL;
	}
		
	else
	{
		while(temp->pre != NULL)
			temp = temp->pre;
		temp->pre = newnode;
		newnode->pre = NULL;
	}
	temp = NULL;
	free(temp);
}

//가장의 앞의 노드를 꺼낸다. 
void pop(queue *q)
{
	if(q->head == NULL)
		return;
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	q->head = temp->pre;
	free(temp);
}

//큐가 비어있으면 1,아니면 0를 반환한다. 
int empty(queue* q)
{
	if(q->head == NULL)
		return 1;
	else
		return 0;
}

//모든 노드를 출력한다. 
void printqueue(queue *q)
{
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	printf("queue:");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->pre;
	}
	temp = NULL;
	free(temp);
	printf("\n");
}

//가장의 앞의 노드를 반환한다. 
int front(queue *q)
{
	if(q->head == NULL)
		return 0;
		
	return q->head->data;
}

//모든 노드를 해제 
void freequeue(queue *q)
{
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	while(!empty(q))
		pop(q);
	temp = NULL;
	free(temp);
}

int main()
{
	int i;
	queue *q = createqueue();
	
//	for(i = 1; i < 101; i++)
//		push(q,i);

	
	push(q,5);
	push(q,6);
	push(q,10);
	push(q,90);
	pop(q);
	pop(q);
	push(q,7);
	push(q,78);
	pop(q);
	push(q,30);
	
	printqueue(q);
	freequeue(q);
	printqueue(q);
	
	
	return 0;
}
