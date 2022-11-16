#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*
	C언어로 Doublelinkedlist구현해보기
	만든사람: taehyeon-park
	깃 허브 :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/doublelinkedlist.c
*/
bool Power = true;
typedef struct NODE{
	struct NODE* llink;
	int data;
	struct NODE* rlink;
}node;

typedef struct Nodelist{
	struct NODE *head;
	struct NODE *tail;
}nodelist;

void back_add_node(struct Nodelist *h,struct NODE *a);
void add_node(struct Nodelist *h,struct NODE *a);
void insert_node(node* target,int data);
node* search_node(nodelist* h,int data);
void print_node_list(nodelist* h,int a);
void delete_node(nodelist *h,node* a);
nodelist* create_nodelist();
node* create_node(int data);
void freenode(nodelist* h);
void print_menu();
void Run();

int main(){
	Run();
	return 0;
}	
		
nodelist* create_nodelist() //노드 리스트 생성 
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
	return newnodelist;
}


node* create_node(int data)//노드 생성 
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	return newnode;
}

void back_add_node(struct Nodelist *h,struct NODE *a)//맨 뒤에 노드생성 
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
		{
			if(temp->rlink->data == a->data)
			{
				printf("%d already exists\n",a->data);
				temp = NULL;
				a = NULL;
				free(temp);
				free(a);
				return;
			} 
			temp = temp->rlink;
		}
			
			
		a->rlink = h->tail;
		a->llink = temp;
		h->tail->llink = a;
		temp->rlink = a;
	}
	
	temp = NULL;
	free(temp);
}


void add_node(struct Nodelist *h,struct NODE *a)//맨앞에 생성 
{
	node* temp = malloc(sizeof(node));
	temp = h->head;
	while(temp->rlink != h->tail)
	{
		if(temp->rlink->data == a->data)
		{
			printf("%d already exists\n",a->data);
			temp = NULL;
			a = NULL;
			free(temp);
			free(a);
			return;
		}
		temp = temp->rlink;
	}
	a->rlink = h->head->rlink;
	a->rlink->llink = a;
	h->head->rlink = a;
	a->llink = h->head;
}


void delete_node(nodelist *h,node* a)//노드 삭제 
{
	node* temp = (node*)malloc(sizeof(node));
	temp = h->head->rlink;
	
	while(temp != a)
		temp = temp->rlink;

	temp->llink->rlink = temp->rlink;
	temp->rlink->llink = temp->llink;
	free(temp);
}


void insert_node(node* target,int data)// 노드 삽입 
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
//	printf("%d뒤에 %d삽입\n",target->data,data);
}


node* search_node(nodelist* h,int data)//특정 노드 검색 
{
	if(h->head->rlink == h->tail)
		return NULL;
	node* temp = malloc(sizeof(node));
	temp = h->head->rlink;

	while(temp->data != data)
	{
		if(temp == h->tail)
			return NULL;
		temp = temp->rlink;
	}
	return temp;
}


void print_node_list(nodelist* h,int a)//모든 노드 출력 
{
	node* temp = (node*)malloc(sizeof(node));
	
	
	if(a == 1)
	{
		printf("linklist : ");
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
}

void print_menu()
{
	printf("		 ============Menu============\n");
	printf("		 1. Add Head Data.\n");
	printf("		 2. Add Tail Data.\n");
	printf("		 3. Delete Data.\n");
	printf("		 4. Insert Data.\n");
	printf("		 5. Print_LinkedList.\n");
	printf("		 6. Delete_LinkedList.\n");
	printf("		 7. clear Display.\n");
	printf("		 8. Exit.\n");
}

void Run()
{
	nodelist *list = create_nodelist();
	print_menu();
	while(Power)
	{
		int data,Choice,insert_back,print_choice,delete_data;
		printf("select----> : ");
		scanf("%d",&Choice);
		switch(Choice)
		{
			case 1:
				printf("Data input : ");
				scanf("%d",&data);
				add_node(list,create_node(data));
				break;
			case 2:
				printf("Data input : ");
				scanf("%d",&data);
				back_add_node(list,create_node(data));
				break;
			case 3:
				printf("Select data to delete : ");
				scanf("%d",&delete_data);
				node* a = search_node(list,delete_data);
				if(a == NULL){printf("%d is not exits\n",delete_data);}
				else{delete_node(list,a);}
				a = NULL;
				free(a);
				break;
			case 4:
				printf("Select the previous node to be inserted : ");
				scanf("%d",&insert_back);
				if(search_node(list,insert_back) == NULL)
				{
					printf("%d does not exist.\n",insert_back);
					continue;
				}
				printf("Data input : ");
				scanf("%d",&data);
				insert_node(search_node(list,insert_back),data);
				break;
			case 5:
				printf("	  1.From the Head\n");
				printf("	  2.From the Tail\n");
				printf("---->>> : ");
				scanf("%d",&print_choice);
				if(print_choice == 1)
					print_node_list(list,1);
				else if(print_choice == 2)
					print_node_list(list,0);
				else
					printf("Wrong choice!!\n");
				break;
			case 6:
				freenode(list);
				break;
			case 7:
				system("cls");
				print_menu();
				break;
			case 8:
				Power = !Power;
				break;
			default:
				printf("Wrong choice!!\n");
				break;
		}
	}
}

