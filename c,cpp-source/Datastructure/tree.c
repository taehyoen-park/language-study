#include<stdio.h>

typedef struct node *treepointer;
typedef struct node {
	int data;
	treepointer lc,rc;
}node;

void preorder(treepointer ptr)
{
	if(ptr)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);
	}
}

void inorder(treepointer ptr)
{
	if(ptr)
	{
		inorder(ptr->lc);
		printf("%d ",ptr->data);
		inorder(ptr->rc);
	}
}

void postorder(treepointer ptr)
{
	if(ptr)
	{
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d ",ptr->data);
	}
}
int main()
{
	int i;
	node nodes[16];
	for(i = 1; i < 16; i++)
	{
		nodes[i].data = i;
		nodes[i].lc = NULL;
		nodes[i].rc = NULL;
	}

	
	for(i = 1; i < 16; i++)
	{
		if(i % 2 == 0)
			nodes[i/2].lc = &nodes[i];
		else
			nodes[i/2].rc = &nodes[i];
	}
	
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1]);
	return 0;
}
