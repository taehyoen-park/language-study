#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#define BinarySearchTree BST

/*
	C++���� binarySearchTree�����غ��� (�ݺ���) 
	������: taehyeon-park
	�� ��� :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/BinarySearchTree.cpp
*/

using namespace std;
typedef long long ll;
class node;
class tree;
int Choice;
bool Power = true;

typedef node* Node;
class node{
public:
	Node Lc; // leftchild
	Node Rc; // rightchild
	ll Data;
	node(ll data) : Data(data), Lc(nullptr), Rc(nullptr) {};
};

typedef tree* Tree;
class tree{
public:
	Node root;
	tree():root(nullptr){}
};

Tree MakeBinarySearchTree();
void DeleteNode(Tree BST);
void InsertNode(Tree Bst);
Node FindNode(Tree BST,ll target);
void Print_BinarySearchTree(Node root);
void PrintMenu();
Node GetParent(Tree BST,ll target);

int main()
{
	Tree BinarySearchTree =	MakeBinarySearchTree();
	while(Power)
	{
		PrintMenu();
		printf("select---> ");
		scanf("%lld", &Choice);
		switch(Choice)
		{
			case 1:
				
				InsertNode(BST);
				break;
			case 2:
				ll target;
				printf("Please enter the data to search for : ");
				scanf("%lld",&target);
				if(FindNode(BST,target) == nullptr) printf("That data not exists.\n");
				else printf("That data exists.\n");
				break;
			case 3:
				DeleteNode(BST);
				break;
			case 4:
				Print_BinarySearchTree(BST->root);
				printf("\n");
				break;
			case 5:
				system("cls");
				break;
			case 6:
				//DeleteBinarySearchTree(BST->root);
				delete BinarySearchTree;
				Power = !Power;
				break;
			default:
				printf("Wrong choice!!\n");
				fflush(stdin);
				break;	
		}
	}
	return 0;
}

Tree MakeBinarySearchTree()
{
	Tree BinarySeachTree = new tree;
	return BinarySeachTree;
}

Node FindNode(Tree BST,ll target)
{
	Node root = BST->root;
	while(root->Data != target)
	{
		if(root->Data < target)
		{
			if(root->Rc == nullptr) return nullptr;
			root = root->Rc;
		}
			
		else
		{
			if(root->Lc == nullptr) return nullptr;
			root = root->Lc;
		}
	}
	return root;
}

void InsertNode(Tree BST)
{
	ll data;
	printf("Data Input : ");
	scanf("%lld", &data);
	Node new_node = new node(data);
	Node root = BST->root;
	
	if(root == nullptr)
	{
		BST->root = new_node;
		return;
	}
	while(true)
	{
		if(root->Data < new_node->Data)
		{
			if(root->Rc == nullptr)
			{
				root->Rc = new_node;
				break;
			}
			else root = root->Rc;
		}
		else
		{	
			if(root->Lc == nullptr)
			{	
				root->Lc = new_node;
				break;
			}
			else root = root->Lc;
		}
	}
}

void DeleteNode(Tree BST)
{
	ll target;
	printf("Please enter the data to be deleted : ");
	scanf("%lld",&target);
	Node TargetNode = FindNode(BST,target);
	
	//�����ҷ��� �ϴ� ��尡 �������� ���� �� 
	if(TargetNode == nullptr)
	{
		printf("The data to be deleted does not exist.\n");
		return; 
	}
	
	//�����ҷ��� �ϴ� ��尡 ����,������ �ڽ��� �Ѵ� ������ �� 
	if(TargetNode->Rc != nullptr && TargetNode->Lc != nullptr)
	{
		Node RightSubTreeRoot = TargetNode->Rc;
		Node RightSubTree_MinChild = TargetNode->Rc;
		
		// �������� ������ ���� Ʈ������ ���� ���� ���� RightSubTree_MinChild�� �����Ѵ�. 
		while(RightSubTree_MinChild->Lc != nullptr)
			RightSubTree_MinChild = RightSubTree_MinChild->Lc;
		
		//������ ����� ������ ����Ʈ���� ��Ʈ��尡 ���� ���� ����϶� 
		if(RightSubTreeRoot == RightSubTree_MinChild)
		{
			TargetNode->Data = RightSubTree_MinChild->Data;
			TargetNode->Rc = RightSubTree_MinChild->Rc;
			RightSubTree_MinChild->Rc = nullptr;
			delete RightSubTree_MinChild;
		}
		
		else
		{
			// RightSubTree_MinChild�� �θ� ã�Ƽ� RightSubTree�� �ִ´�. 
			RightSubTreeRoot = GetParent(BST,RightSubTree_MinChild->Data);
			
			//RightSubTree_MinChild�� ������ ���� Ʈ���� �ڽ��� �θ� RightSubTree�� ���� ����Ʈ���� �ִ´�.
			TargetNode->Data = RightSubTree_MinChild->Data;	
			RightSubTreeRoot->Lc = RightSubTree_MinChild->Rc;
			delete RightSubTree_MinChild;
		}
	}
	
	//�����ҷ��� �ϴ� ��尡 ����,������ �ڽ��� �Ѵ� ������ �� or ���߿� �ϳ� ������ �� 
	else
	{
		//���� ����� �θ� ���� 
		Node TargetNodeRoot = GetParent(BST,target);
		
		//���� ��尡 ��������϶� 
		if(TargetNode->Rc == nullptr && TargetNode->Lc == nullptr)
		{
			if(TargetNodeRoot->Data < target) TargetNodeRoot->Rc = nullptr;
			else TargetNodeRoot->Lc = nullptr;
			delete TargetNode;
			return;
		}
		
		// ---- ������ ��尡 �����̳� �������� �ϳ��� �ڽ��� ������ ���� �� ---- //
		
		//�������� �θ� ��Ʈ����϶� 
		if(TargetNodeRoot == BST->root) 
		{
			if(BST->root->Rc != nullptr)
			{
				BST->root = TargetNode->Rc;
				delete TargetNode;
				return;
			}
			else
			{
				BST->root = TargetNode->Lc;
				delete TargetNode;
				return;
			}
		}
		
		//�������� ������ ����Ʈ���� ��尡 ������ (���ʼ���Ʈ���� �ƹ��͵� ������������) 
		if(TargetNode->Rc != nullptr)
		{	
			//������θ��� �������� �������϶� 
			if(TargetNodeRoot->Data < target) TargetNodeRoot->Rc = TargetNode->Rc;
			else TargetNodeRoot->Lc = TargetNode->Rc;
			delete TargetNode;
		}
		
		else
		{
			if(TargetNodeRoot->Data < target) TargetNodeRoot->Rc = TargetNode->Lc;
			else TargetNodeRoot->Lc = TargetNode->Lc;
			delete TargetNode;
		}
		
	}
}

Node GetParent(Tree BST,ll target)
{
	Node TargetNodeRoot = BST->root;
	Node TargetNode = BST->root;
	//���� ����� �θ� ã�´�
	while(TargetNode->Data != target)
	{
		TargetNodeRoot = TargetNode;
		if(TargetNode->Data < target)
		{
			if(TargetNode->Rc == nullptr) break;
			TargetNode = TargetNode->Rc;
		}
			
		else
		{
			if(TargetNode->Lc == nullptr) break;
			TargetNode = TargetNode->Lc;
		}
	}
	return TargetNodeRoot;
}

void Print_BinarySearchTree(Node root) {
    if (root == nullptr) {
        return;
    }
   	Print_BinarySearchTree(root->Lc);
    cout << root->Data << " ";
    Print_BinarySearchTree(root->Rc);
}

void DeleteBinarySearchTree(Node target)
{
	if(target == nullptr) return; 
	DeleteBinarySearchTree(target->Lc);
	DeleteBinarySearchTree(target->Rc);
	delete target;
}
void PrintMenu()
{
	printf("	============Menu============\n");
	printf("	1. Add Data\n");
	printf("	2. Serch Data\n");
	printf("	3. Delete Data.\n");
	printf("	4. Print_BinarySearchTree.\n");
	printf("	5. clear Display.\n");
	printf("	6. Exit.\n");
	printf("	============================\n");
}




