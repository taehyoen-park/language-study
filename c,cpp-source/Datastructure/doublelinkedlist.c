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

nodelist* create_nodelist() //��� ����Ʈ ���� 
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
   	printf("------------������ �Ӹ����� �����Ͱ� ����(0).----------\n\n");
	return newnodelist;
}

node* create_node(int data)//��� ���� 
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	return newnode;
}

void back_add_node(struct Nodelist *h,struct NODE *a)//�� �ڿ� ������ 
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
	printf("�ǵڳ��%d�߰�\n",a->data);
	free(temp);
}

void add_node(struct Nodelist *h,struct NODE *a)//�Ǿտ� ���� 
{
	a->rlink = h->head->rlink;
	a->rlink->llink = a;
	h->head->rlink = a;
	a->llink = h->head;
	printf("�Ǿճ��%d�߰�\n",a->data); 
}

void delete_node(nodelist *h,node* a)//��� ���� 
{
	node* temp = (node*)malloc(sizeof(node));
	temp = h->head->rlink;
	
	while(temp != a)
		temp = temp->rlink;
	
	temp->llink->rlink = temp->rlink;
	temp->rlink->llink = temp->llink;
	printf("%d����\n",a->data);
	free(temp);
	
}

void insert_node(node* target,int data)// ��� ���� 
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
	printf("%d�ڿ� %d����\n",target->data,data);
}

node* search_node(nodelist* h,int data)//Ư�� ��� �˻� 
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

void print_node_list(nodelist* h,int a)//��� ��� ��� 
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

void freenode(nodelist* h)// ��� ��� ���� 
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
   	printf("������ �Ӹ��� ������ ����带 ����\n");
}

int main()
{
	nodelist *A = create_nodelist();
	
	
	insert_node(A->head,10);
	back_add_node(A,create_node(30));
	add_node(A,create_node(20));
	delete_node(A,search_node(A,20));
	insert_node(search_node(A,30),60);
	insert_node(search_node(A,60),80);
	delete_node(A,search_node(A,30));
	back_add_node(A,create_node(100));
	
	print_node_list(A,1);
	freenode(A);
	print_node_list(A,1);
	
	return 0;
}	
		

