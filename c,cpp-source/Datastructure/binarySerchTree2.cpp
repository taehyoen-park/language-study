#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#define BinarySearchTree BST

/*
	C++언어로 binarySearchTree구현해보기 (반복문) 
	만든사람: taehyeon-park
	깃 허브 :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/BinarySearchTree.cpp
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
	
	//삭제할려고 하는 노드가 존재하지 않을 때 
	if(TargetNode == nullptr)
	{
		printf("The data to be deleted does not exist.\n");
		return; 
	}
	
	//삭제할려고 하는 노드가 왼쪽,오른쪽 자식이 둘다 존재할 때 
	if(TargetNode->Rc != nullptr && TargetNode->Lc != nullptr)
	{
		Node RightSubTreeRoot = TargetNode->Rc;
		Node RightSubTree_MinChild = TargetNode->Rc;
		
		// 삭제할의 오른쪽 서브 트리에서 가장 작은 값을 RightSubTree_MinChild에 저장한다. 
		while(RightSubTree_MinChild->Lc != nullptr)
			RightSubTree_MinChild = RightSubTree_MinChild->Lc;
		
		//삭제할 노드의 오른쪽 서브트리의 루트노드가 가장 작은 노드일때 
		if(RightSubTreeRoot == RightSubTree_MinChild)
		{
			TargetNode->Data = RightSubTree_MinChild->Data;
			TargetNode->Rc = RightSubTree_MinChild->Rc;
			RightSubTree_MinChild->Rc = nullptr;
			delete RightSubTree_MinChild;
		}
		
		else
		{
			// RightSubTree_MinChild의 부모를 찾아서 RightSubTree에 넣는다. 
			RightSubTreeRoot = GetParent(BST,RightSubTree_MinChild->Data);
			
			//RightSubTree_MinChild의 오른쪽 서브 트리를 자신의 부모 RightSubTree의 왼쪽 서브트리에 넣는다.
			TargetNode->Data = RightSubTree_MinChild->Data;	
			RightSubTreeRoot->Lc = RightSubTree_MinChild->Rc;
			delete RightSubTree_MinChild;
		}
	}
	
	//삭제할려고 하는 노드가 왼쪽,오른쪽 자식이 둘다 존재할 때 or 돌중에 하나 존재할 때 
	else
	{
		//지울 노드의 부모를 구함 
		Node TargetNodeRoot = GetParent(BST,target);
		
		//지울 노드가 리프노드일때 
		if(TargetNode->Rc == nullptr && TargetNode->Lc == nullptr)
		{
			if(TargetNodeRoot->Data < target) TargetNodeRoot->Rc = nullptr;
			else TargetNodeRoot->Lc = nullptr;
			delete TargetNode;
			return;
		}
		
		// ---- 삭제할 노드가 왼쪽이나 오른쪽중 하나의 자식을 가지고 있을 때 ---- //
		
		//지울노드의 부모가 루트노드일때 
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
		
		//지울노드의 오른쪽 서브트리에 노드가 존재함 (왼쪽서브트리는 아무것도 존재하지않음) 
		if(TargetNode->Rc != nullptr)
		{	
			//지울노드부모의 오른쪽이 지울노드일때 
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
	//지울 노드의 부모를 찾는다
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




