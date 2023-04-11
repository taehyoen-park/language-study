#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<Windows.h> 

/*
	C++���� AvlTree�����غ��� 
	������: taehyeon-park
	�� ��� :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/AvlTree.cpp
*/

using namespace std;

class Node;
class AvlTree;
typedef Node* node;
class Node {
public:
	node Rc;
	node Lc;
	int data, height, balance;
	Node(int data) :data(data), height(0), balance(0), Rc(nullptr), Lc(nullptr) {};
};

typedef AvlTree* avlTree;
class AvlTree {
public:
	node root;
	AvlTree() : root(nullptr) {}
};

avlTree MakeAvlTree();
void PrintMenu(); 
void Print_AvlTree(node root,int choice);
node GetMaxDepthNodeInRightSubtree(node& rSubTreeRoot);
void RoateLL(avlTree& avltree, node& rootNode);
void RoateRR(avlTree& avltree, node& rootNode);
void RotateLR();
void RotateRL(); 
void UpdateBalance(node& avltreeRoot,node& rootNode); 
void UpdateHeight(node& avltreeRoot,node& rootNode); 	
void CheckAvlTree(avlTree& avltree, node& rootNode);
void BalancIngAvlTree(avlTree& avltree, node& rootNode); 
void InsertNode(node& rootNode, int data);
node SearchNode(node& rootNode, int data);
node DeleteNode(node& rootNode,int data);
node GetParent(node& rootNode, node& TargetNode);
void DeleteAvlTree(node rootNode);
node GetRightSubTreeMinNode(node& rootNode);

int main()
{
	int choice, dataCount, inputData,dataSize = 0;
	bool power = true;
	node targetNode; 
	avlTree avltree = MakeAvlTree();
	PrintMenu();
	while (power)
	{
		printf(" 	select---> ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			cout << " How many data do you want to input? : ";
			scanf("%d", &dataCount);
			printf(" Data Input : ");
			for (int i = 0; i < dataCount; i++)
			{
				scanf("%d", &inputData);
				targetNode = SearchNode(avltree->root, inputData);
				if (targetNode != nullptr)
					printf(" %d is already exists\n",inputData);
				else
				{
					dataSize++;
					InsertNode(avltree->root, inputData);
					targetNode = SearchNode(avltree->root,inputData);
					BalancIngAvlTree(avltree, targetNode);
				}
			}
			break;
		case 2:
			printf(" Please enter the data to search for : ");
			scanf("%d",&inputData);
			if(SearchNode(avltree->root,inputData) == nullptr) 
				printf(" %d not exists.\n",inputData);
			else 
				printf(" That data exists.\n");
			break;
		case 3:
			printf(" Please enter the data to be deleted : ");
			scanf("%d",&inputData);
			targetNode = SearchNode(avltree->root,inputData);
			if(targetNode == nullptr) 
				printf(" Data not found for deletion.\n");
			else 
			{
				dataSize--;
				node targetNodeParent = GetParent(avltree->root,targetNode);
				avltree->root = DeleteNode(avltree->root,inputData);
				if(targetNodeParent == nullptr)
					targetNodeParent =  GetMaxDepthNodeInRightSubtree(avltree->root);
				if(targetNodeParent == nullptr)
				{
					printf(" AvlTree is Empty\n");
					break;
				}
				BalancIngAvlTree(avltree, targetNodeParent);
			}		
			break;
		case 4:
			printf("	1.���� ����(preorder)\n");
			printf("	2.���� ����(inorder)\n");
			printf("	3.���� ����(postorder)\n");
			printf("	select---> ");
			scanf("%d",&choice);
			printf("	Data(%d��) : ",dataSize);
			Print_AvlTree(avltree->root,choice);
			cout << endl;
			break;
		case 5:
			PrintMenu();
			break;
		case 6:
			system("cls");
			PrintMenu();
			break;
		case 7:
			DeleteAvlTree(avltree->root);
			avltree->root = nullptr;
			dataSize = 0;
			break;	
		case 8:
			DeleteAvlTree(avltree->root);
			delete avltree;
			power = !power;
			break;

		default:
			printf(" Wrong choice!!\n");
			fflush(stdin);
			break;
		}
	}
	return 0;
}

// �������� ���̸� ������Ʈ�ϴ� �Լ� 
void UpdateHeight(node& avltreeRoot,node& rootNode)
{
	int leftChild, rightChild;
	if (rootNode->Lc == nullptr) leftChild = -1;
	else leftChild = rootNode->Lc->height;
	if (rootNode->Rc == nullptr) rightChild = -1;
	else rightChild = rootNode->Rc->height;
	
	int result = max(leftChild, rightChild);
	rootNode->height = result + 1;
	node parentNode = GetParent(avltreeRoot, rootNode);
	if (parentNode != nullptr) UpdateHeight(avltreeRoot, parentNode);
	return;
}

// �������� �뷱���� ������Ʈ�ϴ� �Լ� 
void UpdateBalance(node& avltreeRoot,node& rootNode)
{
	int leftHeight, rightHeight;
	if (rootNode->Lc == nullptr) leftHeight = -1;
	else leftHeight = rootNode->Lc->height;
	if (rootNode->Rc == nullptr) rightHeight = -1;
	else rightHeight = rootNode->Rc->height;
	
	int result = leftHeight - rightHeight;
	rootNode->balance = result;
	node parentNode = GetParent(avltreeRoot, rootNode);
	if (parentNode != nullptr) UpdateBalance(avltreeRoot, parentNode);
	return;
}

//  ����,�뷱�� ������Ʈ�� ȸ���� ��Ű�� �Լ� 
void BalancIngAvlTree(avlTree& avltree, node& targetNode)
{
	UpdateHeight(avltree->root,targetNode);
	UpdateBalance(avltree->root,targetNode);
	CheckAvlTree(avltree, targetNode);
}

//------------------------------ȸ��------------------------------------// 
void RotateLL(avlTree& avltree, node& rootNode)
{
	//cout << "LL" << endl;
	node rootNodeParent = GetParent(avltree->root, rootNode); //���� ����� �θ� 

	// 1.�θ� ��带 �����ڽ��� �����ڽ����� �����Ѵ�.
	node newRootNode = rootNode->Lc;
	node newRootNodeRc = newRootNode->Rc;
	rootNode->Lc = nullptr;
	newRootNode->Rc = rootNode;

	if(rootNodeParent == nullptr)
	{
		rootNode->Lc = newRootNodeRc;
		avltree->root = newRootNode;
	}
	else
	{
		if (rootNodeParent->data < rootNode->data)
		{
			rootNode->Lc = newRootNodeRc;
			rootNodeParent->Rc = newRootNode;
		}
			
		else
		{
			rootNode->Lc = newRootNodeRc;
			rootNodeParent->Lc = newRootNode;
		}
	} 
	
	//Ʈ�� ���� ���� 
	UpdateHeight(avltree->root,rootNode);
	UpdateBalance(avltree->root,rootNode);
}

void RotateRR(avlTree& avltree, node& rootNode)
{
	//cout << "RR" << endl;
	node rootNodeParent = GetParent(avltree->root, rootNode);
	
	// 1.�θ� ��带 ���� �ڽĳ���� �����ڽ����� �����Ѵ�.
	node newRootNode = rootNode->Rc;
	node newRootNodeLc = newRootNode->Lc;	
	rootNode->Rc = nullptr;
	newRootNode->Lc = rootNode;
	
	if(rootNodeParent == nullptr) 
	{	
		rootNode->Rc = newRootNodeLc;
		avltree->root = newRootNode;
	}
	else 
	{
		if (rootNodeParent->data < rootNode->data)
		{
			rootNode->Rc = newRootNodeLc;
			rootNodeParent->Rc = newRootNode;
		}
		else
		{
			rootNode->Rc = newRootNodeLc;
			rootNodeParent->Lc = newRootNode;
		}
	}
	
	//Ʈ�� ���� ���� 
	UpdateHeight(avltree->root,rootNode);
	UpdateBalance(avltree->root,rootNode);
}

void RotateLR(avlTree& avltree, node& rootNodeLc, node& rootNode)
{
	//cout << "LR" << endl;
	RotateRR(avltree, rootNodeLc);
	RotateLL(avltree, rootNode);
	return;
}

void RotateRL(avlTree& avltree, node& rootNodeRc, node& rootNode)
{
	//cout << "RL" << endl;
	RotateLL(avltree, rootNodeRc);
	RotateRR(avltree, rootNode);
	return;
}
//--------------------------------ȸ��--------------------------------//

// ������ Ʋ�������� Ȯ���ϰ� ȸ���� ��Ű�� �Լ� 
void CheckAvlTree(avlTree& avltree, node& rootNode)
{
	if (rootNode == nullptr) return;
	
	int balance = rootNode->balance;
	if (abs(balance) > 1)
	{
		int leftBalance, rightBalance;
		if (rootNode->Lc == nullptr) leftBalance = -1;
		else leftBalance = rootNode->Lc->balance;
		if (rootNode->Rc == nullptr) rightBalance = -1;
		else rightBalance = rootNode->Rc->balance;
		
		if(balance < -1 && rightBalance <= 0) 
			RotateRR(avltree, rootNode);
		else if (balance > 1 && leftBalance >= 0)
			RotateLL(avltree,rootNode);	
		else if(balance < -1 && rightBalance >= 0) 
			RotateRL(avltree, rootNode->Rc, rootNode);
		else if (balance > 1 && leftBalance <= 0)
			RotateLR(avltree, rootNode->Lc, rootNode);	
		else return;
	}
	else
	{
		node parentNode = GetParent(avltree->root, rootNode);
		if(parentNode != nullptr) CheckAvlTree(avltree, parentNode);	
	}
	return;
}

// data�� ã�� �Լ� 
node SearchNode(node& rootNode, int data)
{
	node result = nullptr;
	if (rootNode == nullptr) return nullptr;
	else if (rootNode->data == data) return rootNode;
	else if (rootNode->data < data) result = SearchNode(rootNode->Rc, data);
	else result = SearchNode(rootNode->Lc, data);
	return result;
}

// data�� �����ϴ� �Լ�  
void InsertNode(node& rootNode, int data)
{
	if (rootNode == nullptr) rootNode = new Node(data);
	else if (rootNode->data < data) InsertNode(rootNode->Rc, data);
	else InsertNode(rootNode->Lc, data);
}

// data�� �����ϴ� �Լ� 
node DeleteNode(node& rootNode,int data)
{
	if(rootNode == NULL) 
		return NULL;
		
	if(rootNode->data < data)
		rootNode->Rc = DeleteNode(rootNode->Rc,data);
	else if(rootNode->data > data)
		rootNode->Lc = DeleteNode(rootNode->Lc,data);
	else
	{
		if(rootNode->Lc != nullptr && rootNode->Rc != nullptr)
		{
			node rightSubTreeMinNode = GetRightSubTreeMinNode(rootNode);
			rootNode->data = rightSubTreeMinNode->data;
			rootNode->Rc = DeleteNode(rootNode->Rc,rightSubTreeMinNode->data);
		}
		else
		{
			node returnNode = (rootNode->Lc == nullptr) ? rootNode->Rc : rootNode->Lc;
			delete rootNode;
			return returnNode;
		}
	}
	return rootNode;
}

// ������ ����Ʈ������ ���� ���� �ִ� ������带 ��ȯ�ϴ� �Լ� 
node GetMaxDepthNodeInRightSubtree(node& rSubTreeRoot)
{
	if(rSubTreeRoot == nullptr) return nullptr;
	if(rSubTreeRoot->Rc == nullptr || rSubTreeRoot->Lc == nullptr) return rSubTreeRoot;
	
	if(rSubTreeRoot->Rc->height > rSubTreeRoot->Lc->height)
		return GetMaxDepthNodeInRightSubtree(rSubTreeRoot->Rc);
	else if(rSubTreeRoot->Rc->height < rSubTreeRoot->Lc->height)
		return GetMaxDepthNodeInRightSubtree(rSubTreeRoot->Lc);
	else return rSubTreeRoot;
		
}

// ������ ����Ʈ������ ���� ���� ���� ��带 ��ȯ�ϴ� �Լ� 
node GetRightSubTreeMinNode(node& rootNode)
{
	node RightSubTree_MinChild = rootNode->Rc;
	while (RightSubTree_MinChild->Lc != nullptr)
		RightSubTree_MinChild = RightSubTree_MinChild->Lc;
	return RightSubTree_MinChild;
}

//�ڽ��� �θ� ��� �Լ� 
node GetParent(node& rootNode, node& TargetNode)
{
	node result = nullptr;
	if (rootNode == nullptr) return nullptr;
	//else if (rootNode == TargetNode) return rootNode; --> �θ� �ڱ� �ڽ��� ��� �ڱ� �ڽ� ��ȯ 
	else if (rootNode->Lc == TargetNode || rootNode->Rc == TargetNode) return rootNode;
	else if (rootNode->data < TargetNode->data) result = GetParent(rootNode->Rc, TargetNode);
	else result = GetParent(rootNode->Lc, TargetNode);
	return result;
}

void PrintMenu()
{
	printf("	------------AVLTree-----------------\n");
	printf("	============Menu============\n");
	printf("	1. Add Data\n");
	printf("	2. Serch Data\n");
	printf("	3. Delete Data.\n");
	printf("	4. Print_AvlTree.\n");
	printf("	5. Print_Menu.\n");
	printf("	6. clear Display.\n");
	printf("	7. clear AvlTree.\n");
	printf("	8. Exit.\n");
	printf("	============================\n");
}

void Print_AvlTree(node root,int choice)
{
	if (root == nullptr)
		return;
		
	switch(choice)
	{
		case 1: // ���� ���� preorder
			cout << root->data << " ";
			Print_AvlTree(root->Lc,choice);
			Print_AvlTree(root->Rc,choice);
			break;
		case 2: // ���� ���� inorder 
			Print_AvlTree(root->Lc,choice);
			cout << root->data << " ";
			Print_AvlTree(root->Rc,choice);
			break;
		case 3: // ���� ���� postorder 
			Print_AvlTree(root->Lc,choice);
			Print_AvlTree(root->Rc,choice);
			cout << root->data << " ";
			break;
		default:
			printf("wrong choice!");
			break;
	}
	return;
}

// avltree�ȿ� �ִ� �����͸� ��� ����� �Լ� 
void DeleteAvlTree(node rootNode)
{
	if(rootNode == nullptr) return; 
	DeleteAvlTree(rootNode->Lc);
	DeleteAvlTree(rootNode->Rc);
	rootNode->Lc = nullptr;
	rootNode->Rc = nullptr;
	delete rootNode;
}

avlTree MakeAvlTree()
{
	avlTree avltree = new AvlTree;
	return avltree;
}

