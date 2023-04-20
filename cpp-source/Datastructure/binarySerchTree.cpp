#include<iostream>
#include<vector>
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
	Node root;
	tree(): root(nullptr){};
};

Tree MakeBinarySearchTree();
//void DeleteNode(Tree& BST,Node& RootNode,ll target);
Node DeleteNode(Node& RootNode,int data);
void InsertNode(Node& RootNode,ll data);
Node SearchNode(Node& RootNode,ll data);
void Print_BinarySearchTree(Node root);
void PrintMenu();
Node GetParent(Node &RootNode,Node &TargetNode);
Node GetRightSubTreeMinNode(Node& RootNode);
void DeleteBinarySearchTree(Node& target);
void SetNullChild(Node& TargetNode);
void ConnectMinNode_RootNode(Tree& BST,Node& DeleteNodeRoot,Node& MinNode,ll target);

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
					BST->root = DeleteNode(BST->root,InputData);
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

// data를 삽입하는 함수  
void InsertNode(Node& RootNode,ll data)
{
	if(RootNode == nullptr) RootNode = new node(data);
	else if(RootNode->Data < data) InsertNode(RootNode->Rc,data);
	else InsertNode(RootNode->Lc,data);
}

// Data를 가지고 있는 노드를 검색하는 함수  
Node SearchNode(Node& RootNode,ll Data)
{
	Node result = nullptr;
	if(RootNode == nullptr) return nullptr;
	else if(RootNode->Data == Data) return RootNode;
	else if(RootNode->Data < Data) result = SearchNode(RootNode->Rc,Data);
	else result = SearchNode(RootNode->Lc,Data);
	return result;
}

// data를 삭제하는 함수 
Node DeleteNode(Node& RootNode,int data)
{
	if(RootNode == nullptr) 
		return nullptr;
		
	if(RootNode->Data < data)
		RootNode->Rc = DeleteNode(RootNode->Rc,data);
	else if(RootNode->Data > data)
		RootNode->Lc = DeleteNode(RootNode->Lc,data);
	else
	{
		if(RootNode->Lc != nullptr && RootNode->Rc != nullptr)
		{
			Node rightSubTreeMinNode = GetRightSubTreeMinNode(RootNode);
			RootNode->Data = rightSubTreeMinNode->Data;
			RootNode->Rc = DeleteNode(RootNode->Rc,rightSubTreeMinNode->Data);
		}
		else
		{
			Node returnNode = (RootNode->Lc == nullptr) ? RootNode->Rc : RootNode->Lc;
			delete RootNode;
			return returnNode;
		}
	}
	return RootNode;
}

// 오른쪽 서브트리의 최소노드를 얻는 함수 
Node GetRightSubTreeMinNode(Node &RootNode)
{
	Node RightSubTree_MinChild = RootNode->Rc;
	while(RightSubTree_MinChild->Lc != nullptr)
		RightSubTree_MinChild = RightSubTree_MinChild->Lc;
	return RightSubTree_MinChild;
}

//자신의 부모를 얻는 함수 
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
        
    cout << root->Data << " ";
   	Print_BinarySearchTree(root->Lc);
    Print_BinarySearchTree(root->Rc);
}

void DeleteBinarySearchTree(Node& target)
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
