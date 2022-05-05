#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUENODE{
	int data;
	struct QUEUENODE *pre;
}node;

typedef struct QUEUE{
	struct QUEUENODE *head;
}queue;

queue* createqueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->head = NULL;
	return q;
}

//��带 �ϳ��� ũ������� ����ִ´�. 
void push(queue *q,int x)
{
	node* newnode = (node*)malloc(sizeof(node));
	node* temp = (node*)malloc(sizeof(node));
	node* temp2 = (node*)malloc(sizeof(node));
	
	temp = q->head;
	temp2 = NULL;
	newnode->data = x;
	

	if(q->head == NULL)
	{
		q->head = newnode;
		newnode->pre = NULL;
		
	}
		
	else
	{
		while(temp->data > x)
		{
			if(temp->pre == NULL)
			{
				temp->pre = newnode;
				newnode->pre = NULL;
				return;
			}
		
			else
			{
				temp2 = temp;
				temp = temp->pre;
			}	
		}
		
		if(temp2 == NULL)
		{
			newnode->pre = temp;
			q->head = newnode;
		}
		
		else
		{
			temp2->pre = newnode;
			newnode->pre = temp;
		}
	}
	temp = NULL;
	temp2 = NULL;
	free(temp);
	free(temp2);
}

//��� �ϳ��� ������. 
void pop(queue *q)
{
	if(q->head == NULL)
		return;
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	q->head = temp->pre;
	free(temp);
}

//ť�� ��������� 1 �ƴϸ� 0�� ��ȯ�Ѵ�.  
int empty(queue* q)
{
	if(q->head == NULL)
		return 1;
	else
		return 0;
}

//��� ť�� ��带 ��� 
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

//������ ���� ��带 ��ȯ�Ѵ�. 
int	front(queue *q)
{
	if(q->head == NULL)
		return 0;
		
	return q->head->data;
}

//��� ť�� ��带 ���� 
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
	
//	for(i = 1; i < 100; i++)
//		push(q,i);
	
	push(q,5);
	push(q,6);
	push(q,10);
	push(q,90);
	//pop(q);
	//pop(q);
	push(q,7);
	push(q,78);
	//pop(q);
	push(q,30);
	//pop(q);
	
	printqueue(q);
	freequeue(q);
	printqueue(q);
	
	return 0;
}
