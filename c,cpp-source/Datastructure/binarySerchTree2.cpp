
#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#define BinarySearchTree BST

/*
	C++언어로 binarySearchTree구현해보기 
	만든사람: taehyeon-park
	깃 허브 :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/BinarySearchTree.cpp
*/

using namespace std;
typedef long long ll;
class node;
class tree;
int Choice;
ll InputData,DataCount;
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
	Node
	root;
	tree(): root(nullptr){}
};

Tree MakeBinarySearchTree();
void DeleteNode(Tree& BST,Node& RootNode,ll target);
void InsertNode(Node& RootNode,ll data);
Node SearchNode(Node& RootNode,ll data);
void Print_BinarySearchTree(Node root);
void PrintMenu();
Node GetParent(Node &RootNode,Node &TargetNode);
Node GetRightSubTreeMinNode(Node &RootNode);
void DeleteBinarySearchTree(Node target);
void SetNullChild(Node& TargetNode);

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
				cout << "How many data do you want to input? : ";
				scanf("%lld", &DataCount);
				printf("Data Input : ");
				for(int i = 0; i < DataCount;i++)
				{
					scanf("%lld",&InputData);
					if(SearchNode(BST->root,InputData) != nullptr) 
						printf("The data already exists\n");
					else 
						InsertNode(BST->root,InputData);
				}
				break;
			case 2:
				printf("Please enter the data to search for : ");
				scanf("%lld",&InputData);
				if(SearchNode(BST->root,InputData) == nullptr) 
					printf("That data not exists.\n");
				else 
					printf("That data exists.\n");
				break;
			case 3:
				printf("Please enter the data to be deleted : ");
				scanf("%lld",&InputData);
				if(SearchNode(BST->root,InputData) == nullptr) 
					printf("Data not found for deletion.\n");
				else 
					DeleteNode(BST,BST->root,InputData);
				break;
			case 4:
				printf("BST Data : ");
				Print_BinarySearchTree(BST->root);
				printf("\n");
				break;
			case 5:
				system("cls");
				break;
			case 6:
				DeleteBinarySearchTree(BST->root);
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

void InsertNode(Node& RootNode,ll data)
{
	if(RootNode == nullptr) RootNode = new node(data);
	else if(RootNode->Data < data) InsertNode(RootNode->Rc,data);
	else InsertNode(RootNode->Lc,data);
}

Node SearchNode(Node& RootNode,ll Data)
{
	Node result = nullptr;
	if(RootNode == nullptr) return nullptr;
	else if(RootNode->Data == Data) return RootNode;
	else if(RootNode->Data < Data) result = SearchNode(RootNode->Rc,Data);
	else result = SearchNode(RootNode->Lc,Data);
	return result;
}

void DeleteNode(Tree& BST,Node &RootNode,ll target)
{
	if(RootNode == nullptr) return;
	else if(RootNode->Data  == target)
	{
		Node BSTRootNode = BST->root; 
		Node DeleteNode = RootNode;
		Node DeleteNodeRoot = GetParent(BSTRootNode,RootNode);
		
		// 삭제할 노드의 자식이 Rc,Lc 둘다 있을경우 
		if(RootNode->Rc != nullptr && RootNode->Lc != nullptr)
		{
			Node RightSubTreeMinNode = GetRightSubTreeMinNode(DeleteNode);
			Node RightSubTreeMinNodeRc = RightSubTreeMinNode->Rc;
			Node RightSubTreeMinNodeRoot = GetParent(BSTRootNode,RightSubTreeMinNode);
			
			// 삭제할 노드가 트리의 Root인경우 
		//	if(DeleteNode == BSTRootNode) && DeleteNode != RightSubTreeMinNode) 
				
			
			// 오른쪽 서브트리의 최솟값이 오른쪽 서브트리의 Root인경우 
			if(DeleteNode->Rc == RightSubTreeMinNode)
			{
				//삭제할 노드의 자식들을 오른쪽 서브트리의 최소노드에게 이어준다 
				RightSubTreeMinNode->Lc = DeleteNode->Lc;
				//오른쪽 서브트리의 최소노드와 삭제할 노드의 부모와 이어준다 
				if(DeleteNodeRoot->Data < target) 
					DeleteNodeRoot->Rc = RightSubTreeMinNode;
				else if(DeleteNodeRoot->Data > target) 
					DeleteNodeRoot->Lc = RightSubTreeMinNode;
				else
					BST->root = RightSubTreeMinNode;
				SetNullChild(DeleteNode);
				delete DeleteNode;
				return;
			}
			
			else
			{
				 //삭제할 노드의 자식들을 오른쪽 서브트리의 최소노드에게 이어준다 
				RightSubTreeMinNode->Rc = DeleteNode->Rc;
				RightSubTreeMinNode->Lc = DeleteNode->Lc;
				//오른쪽 서브트리의 최소노드와 삭제할 노드의 부모와 이어준다
				if(DeleteNodeRoot->Data < target) 
					DeleteNodeRoot->Rc = RightSubTreeMinNode;
				else if(DeleteNodeRoot->Data > target)
					DeleteNodeRoot->Lc = RightSubTreeMinNode;
				else 
					BST->root = RightSubTreeMinNode;
				// 오른쪽 서브트리의 최소노드의 오른쪽 자식을 최소노드의 부모랑 이어준다. 
				RightSubTreeMinNodeRoot->Lc = RightSubTreeMinNodeRc;
				SetNullChild(DeleteNode);
				delete DeleteNode;
				return;
			}
			return;
		}
		
		// 삭제할 노드가 리프노드인 경우 
		else if(RootNode->Rc == nullptr && RootNode->Lc == nullptr)
		{
			if(DeleteNodeRoot->Data < target)
				DeleteNodeRoot->Rc = nullptr;
			else if(DeleteNodeRoot->Data > target)
				DeleteNodeRoot->Lc = nullptr;
			else 
				BST->root = nullptr;
			delete DeleteNode;
			return;
		}
		
		// 삭제할 노드의 자식이 1개밖에 없을 경우 
		else
		{
			//삭제할 노드의 자식이 오른쪽에 자식이 있을경우 
			if(DeleteNode->Rc != nullptr)
			{
				if(DeleteNodeRoot->Data < target)
					DeleteNodeRoot->Rc = DeleteNode->Rc;
				else if(DeleteNodeRoot->Data > target)
					DeleteNodeRoot->Lc = DeleteNode->Rc;
				else 
					BST->root = DeleteNode->Rc;
			}
			else
			{
				if(DeleteNodeRoot->Data < target)
					DeleteNodeRoot->Rc = DeleteNode->Lc;
				else if(DeleteNodeRoot->Data > target)
					DeleteNodeRoot->Lc = DeleteNode->Lc;
				else
					BST->root = DeleteNode->Lc;
			}
			SetNullChild(DeleteNode);
			delete DeleteNode;
			return;
		}
	}
	
	else if(RootNode->Data < target) DeleteNode(BST,RootNode->Rc,target);
	else DeleteNode(BST,RootNode->Lc,target);
	return;
}

void SetNullChild(Node& TargetNode)
{
	TargetNode->Rc = nullptr;
	TargetNode->Lc = nullptr;
	return;
}

Node GetRightSubTreeMinNode(Node &RootNode)
{
	Node RightSubTree_MinChild = RootNode->Rc;
	while(RightSubTree_MinChild->Lc != nullptr)
		RightSubTree_MinChild = RightSubTree_MinChild->Lc;
	return RightSubTree_MinChild;
}


Node GetParent(Node &RootNode,Node &TargetNode)
{
	Node result = nullptr;
	if(RootNode == nullptr) return nullptr;
	else if(RootNode == TargetNode) return RootNode;
	else if(RootNode->Lc == TargetNode || RootNode->Rc == TargetNode) return RootNode;
	else if(RootNode->Data < TargetNode->Data) result = GetParent(RootNode->Rc,TargetNode);
	else result = GetParent(RootNode->Lc,TargetNode);
	return result;
}

void Print_BinarySearchTree(Node root)
{
    if (root == nullptr) 
        return;
    
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

Tree MakeBinarySearchTree()
{
	Tree BinarySeachTree = new tree;
	return BinarySeachTree;
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
