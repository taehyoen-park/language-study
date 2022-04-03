#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE* llink;
	int data;
	struct NODE* rlink;
}node;

typedef struct Nodelist{
	struct NODE *head;
	struct NODE *tail;
}nodelist;

nodelist* createnodelist() //노드 리스트 생성 
{
	nodelist* newnodelist = (nodelist*)malloc(sizeof(nodelist));
	newnodelist->head = (node*)malloc(sizeof(node));
	newnodelist->tail = (node*)malloc(sizeof(node));
	
	newnodelist->head->data = 0;
	newnodelist->tail->data = 0;
	newnodelist->head->rlink = newnodelist->tail;
  	newnodelist->head->llink = NULL;
   	newnodelist->tail->rlink = NULL;
   	newnodelist->tail->llink = newnodelist->head;
   	printf("------------꼬리와 머리노드는 데이터가 없다(0).----------\n\n");
	return newnodelist;
}

node* createnode(int data)//노드 생성 
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	return newnode;
}

void backaddnode(struct Nodelist *h,struct NODE *a)//맨 뒤에 노드생성 
{
	node* temp = malloc(sizeof(node));
	temp = h->head;
	
	if(temp->rlink == h->tail)
	{
		a->rlink = h->tail;
		a->llink = temp;
		h->tail->llink = a;
		temp->rlink = a;
	}
	else
	{
		while(temp->rlink != h->tail)
			temp = temp->rlink;
			
		a->rlink = h->tail;
		a->llink = temp;
		h->tail->llink = a;
		temp->rlink = a;
	}
	
	temp = NULL;
	printf("맨뒤노드%d추가\n",a->data);
	free(temp);
}

void addnode(struct Nodelist *h,struct NODE *a)//맨앞에 생성 
{
	a->rlink = h->head->rlink;
	a->rlink->llink = a;
	h->head->rlink = a;
	a->llink = h->head;
	printf("맨앞노드%d추가\n",a->data); 
}

void deletenode(nodelist *h,node* a)//노드 삭제 
{
	node* temp = (node*)malloc(sizeof(node));
	temp = h->head->rlink;
	
	while(temp != a)
		temp = temp->rlink;
	
	temp->llink->rlink = temp->rlink;
	temp->rlink->llink = temp->llink;
	printf("%d삭제\n",a->data);
	free(temp);
	
}

void insertnode(node* target,int data)// 노드 삽입 
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	
	if(target == NULL)
	{
		free(newnode);
		return;	
	}
	
	newnode->rlink = target->rlink;
	newnode->rlink->llink = newnode;
	newnode->llink = target;
	target->rlink = newnode;
	printf("%d뒤에 %d삽입\n",target->data,data);
}

node* searchnode(nodelist* h,int data)//특정 노드 검색 
{
	node* temp = malloc(sizeof(node));
	temp = h->head->rlink;
	while(temp->data != data)
	{
		temp = temp->rlink;
		if(temp == h->tail)
			return NULL;
	}
	return temp;
}

void printnodelist(nodelist* h,int a)//모든 노드 출력 
{
	node* temp = (node*)malloc(sizeof(node));
	
	
	if(a == 1)
	{
		printf("linklist:");
		temp = h->head->rlink;
		while(temp != h->tail)
		{
			printf("%d ",temp->data);
			temp = temp->rlink;
		}
		printf("\n");
	}
	else
	{
		printf("(reverse)linklist:");
		temp = h->tail->llink;
		while(temp != h->head)
		{
			printf("%d ",temp->data);
			temp = temp->llink;
		}
		printf("\n");
	}
	temp = NULL;
	free(temp);
}

void freenode(nodelist* h)// 모드 노드 해제 
{
	node *fnode = malloc(sizeof(node));
	fnode = h->head->rlink;

	while(fnode != h->tail)
	{
		h->head = fnode->rlink;
		free(fnode);
		fnode = h->head;
	}
	h->head->rlink = h->tail;
   	h->tail->llink = h->head;
   	
   	fnode = NULL;
   	free(fnode);
   	printf("꼬리와 머리를 제외한 모든노드를 해제\n");
}

int main()
{
	nodelist *A = createnodelist();
	
	
	insertnode(A->head,10);
	backaddnode(A,createnode(30));
	addnode(A,createnode(20));
	deletenode(A,searchnode(A,20));
	insertnode(searchnode(A,30),60);
	insertnode(searchnode(A,60),80);
	deletenode(A,searchnode(A,30));
	backaddnode(A,createnode(100));
	
	printnodelist(A,1);
	freenode(A);
	printnodelist(A,1);
	
	return 0;
}	
		

