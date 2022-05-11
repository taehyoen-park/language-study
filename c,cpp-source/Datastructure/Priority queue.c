#include<stdio.h>
#include<stdbool.h>
#include<windows.h> 
#include<stdlib.h>

/*
	C언어로 우선순위 큐만들기 
	만든사람:taehyeon-park 
	깃허브 : https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/Priority%20queue.c
*/

bool Power = true;
typedef struct QUEUENODE{
	int data;
	struct QUEUENODE *pre;
}node;

typedef struct QUEUE{
	struct QUEUENODE *head;
}queue;

queue* createqueue();
void Run();
void push(queue *q,int x);
void pop(queue *q);
int empty(queue* q);
void printqueue(queue *q);
int	front(queue *q);
void freequeue(queue *q);

int main()
{
	Run();	
	return 0;
}

queue* createqueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->head = NULL;
	return q;
}
//노드를 하나를 크기순으로 집어넣는다. 
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

//노드 하나를 꺼낸다. 
void pop(queue *q)
{
	if(q->head == NULL)
		return;
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	q->head = temp->pre;
	free(temp);
}

//큐가 비어있으면 1 아니면 0을 반환한다.  
int empty(queue* q)
{
	if(q->head == NULL)
		return 1;
	else
		return 0;
}

//모든 큐의 노드를 출력 
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
int	front(queue *q)
{
	if(q->head == NULL)
		return 0;
		
	return q->head->data;
}

//모든 큐의 노드를 해제 
void freequeue(queue *q)
{
	node* temp = (node*)malloc(sizeof(node));
	temp = q->head;
	while(!empty(q))
		pop(q);
	temp = NULL;
	free(temp);
	
}
void print_Menu()
{
	printf("		=====Menu=====\n");
	printf("		 0. show menu\n");
	printf("		 1. push\n");
	printf("		 2. pop\n");
	printf("		 3. print_Queue\n");
	printf("		 4. Delete_Queue\n");
	printf("		 5. clear Display\n");
	printf("		 6. Exit\n");
}
void Run()
{
	queue *q = createqueue();
	int data;
	print_Menu();
	while(Power)
	{
		int Choice;
		printf("---->select : ");
		scanf("%d",&Choice);
		switch (Choice)
		{
			case 0:
				print_Menu();
				break;
			case 1:
				printf("Data input : ");
				scanf("%d",&data);
				push(q,data);
				break;
			case 2:
				if(empty(q))
					printf("queue is empty.\n");
				else
				{
					printf("%d 삭제",front(q));
					pop(q);
				}
				break;
			case 3:
				printqueue(q);
				break;
			case 4:
				freequeue(q);
				break;
			case 5:
				system("cls");
				print_Menu();
				break;
			case 6:
				Power = !Power;
				break;
			default:
				printf("!!! Wrong entered !!!\n\n");
				break;
		}
	}
}
