#include<iostream>

class Node;
class RedBlackTree;
typedef Node* node;
typedef RedBlackTree* redblacktree;
typedef bool Color;

using namespace std;
enum eColor{
	Red,
	Black,
	DoublyBlack
};

class Node{
public:
	node Rc;
	node Lc;
	int data;
	Color color;
	Node(int data):data(data),color(Red),Rc(nullptr),Lc(nullptr){};
};

class RedBlackTree{
public:
	node root;
	RedBlackTree(): root(nullptr){};
};

//const node NILnode = nullptr; // 리프노드 

void PrintMenu();
node GetParent(node& rootNode, node& TargetNode);
node GetRightSubTreeMinNode(node& rootNode);
void Print_RedBlackTree(node root,int choice);
void DeleteRedBlackTree(node rootNode);
void SolveDoublyBlack(redblacktree& RBT,node& doublyNode,node& doublyParent,node& doublyBrother);
void InsertNode(node& rootNode,node& newNode);
node DeleteNode(node& rootNode,int data);
node SearchNode(node& rootNode, int data);
void ReColoring(redblacktree& RBT,node& rootNode,node& grandParent);
void ReStructuring(redblacktree& RBT,node& rootNode,node& parent,node& grandParent);
void BalanceIngRBT(redblacktree& RBT,node& rootNode);
void RoateLL(redblacktree& RBT, node& rootNode);
void RoateRR(redblacktree& RBT, node& rootNode);
void RotateLR(redblacktree& RBT, node& parent, node& grandParent);
void RotateRL(redblacktree& RBT, node& parent, node& grandParent); 

int main()
{
	int choice, dataCount, inputData,dataSize = 0;
	bool power = true;
	node targetNode; 
	
	redblacktree RBT = new RedBlackTree;
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
			for(int i = 0; i < dataCount;i++)
			{
				dataSize++;
				scanf("%d", &inputData);
				node newNode = new Node(inputData);
				InsertNode(RBT->root,newNode);
				BalanceIngRBT(RBT,newNode);
			}

			break;
			
		case 2:
			printf(" Please enter the data to search for : ");
			scanf("%d",&inputData);
			if(SearchNode(RBT->root,inputData) == nullptr) 
				printf(" %d not exists.\n",inputData);
			else 
				printf(" That data exists.\n");
			break;
		case 3:
			printf(" Please enter the data to be deleted : ");
			scanf("%d",&inputData);
			targetNode = SearchNode(RBT->root,inputData);
			if(targetNode == nullptr) 
				printf(" Data not found for deletion.\n");
			else 
			{
				dataSize--;
				node targetNodeParent = GetParent(RBT->root,targetNode);
				
				if(targetNode->Lc != nullptr && targetNode->Rc != nullptr)
				{
					node minNode =  GetRightSubTreeMinNode(targetNode);
					 
					if(minNode->color == Red)
						RBT->root = DeleteNode(RBT->root,inputData);
						
					else 
					{
						node minNodeParent = GetParent(RBT->root,minNode);
						node minNodeBrother = (minNodeParent == targetNode) ? minNodeParent->Lc : minNodeParent->Rc;		   
						if(minNode->Rc != nullptr)
						{
							RBT->root = DeleteNode(RBT->root,inputData);
							minNode = (minNodeParent == targetNode) ? minNode : minNodeParent->Lc;
							
							// 삭제하고 새로 이어진 노드가 Red일 경우 Black으로 변경 ->red-and-black
							if(minNode->color == Red)
								minNode->color = Black;
							else 
							{
								// 새로 이어진 노드가 Black일 경우 -> doublyblack
								minNode->color = DoublyBlack;
								SolveDoublyBlack(RBT,minNode,minNodeParent,minNodeBrother);
							}	
						}

						else
						{
							minNode->color = DoublyBlack;
							SolveDoublyBlack(RBT,minNode,minNodeParent,minNodeBrother);	
							RBT->root = DeleteNode(RBT->root,inputData);
						}
					}
				}
				
				// 삭제할 노드의 자식이 1명이거나 없을 경우 
				else
				{
					node targetNodeChild = (targetNode->Rc == nullptr) ? targetNode->Lc : targetNode->Rc;
					
					if(targetNode->color == Red)
						RBT->root = DeleteNode(RBT->root,inputData);
					
					else
					{
						node targetNodeBrother;
						if(targetNode != RBT->root) 
						{
							targetNodeBrother = targetNodeParent->data < targetNode->data ? 
								targetNodeParent->Lc : targetNodeParent->Rc;
						}
						else targetNodeBrother = nullptr;
											
						if(targetNodeChild == nullptr)
						{		
							targetNode->color = DoublyBlack;
							SolveDoublyBlack(RBT,targetNode,targetNodeParent,targetNodeBrother);
							RBT->root = DeleteNode(RBT->root,inputData);
						}
						
						// 자식이 1명일경우 
						else
						{
							if(targetNodeChild->color == Red)
							{
								targetNodeChild->color = Black;
								RBT->root = DeleteNode(RBT->root,inputData);
							}
							else
							{
								targetNodeChild->color = DoublyBlack;
								RBT->root = DeleteNode(RBT->root,inputData);
			
								if(targetNodeParent == nullptr)
									SolveDoublyBlack(RBT,RBT->root,targetNodeParent,targetNodeBrother);
								else if(targetNodeParent->data < targetNode->data)
									SolveDoublyBlack(RBT,targetNodeParent->Rc,targetNodeParent,targetNodeBrother);
								
								else 
									SolveDoublyBlack(RBT,targetNodeParent->Lc,targetNodeParent,targetNodeBrother);
							}
						}
					}
				}
			}				
			break;
		case 4:
			printf("	1.전위 순위(preorder)\n");
			printf("	2.중위 순위(inorder)\n");
			printf("	3.후위 순위(postorder)\n");
			printf("	select--->");
			scanf("%d",&choice);
			Print_RedBlackTree(RBT->root,choice);
			cout << "\n";
			break;
		case 5:
			PrintMenu();
			break;
		case 6:
			system("cls");
			PrintMenu();
			break;
		case 7:
			DeleteRedBlackTree(RBT->root);
			break;	
		case 8:
			DeleteRedBlackTree(RBT->root);
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

void BalanceIngRBT(redblacktree& RBT,node& rootNode)
{
	if(rootNode == RBT->root) // rootNode가 가장위에 있는 노드일때 
	{
		rootNode->color = Black;
		return;
	}
	
	node Parent = GetParent(RBT->root,rootNode);
	node GrandParent = GetParent(RBT->root,Parent);
	
	if(Parent->color == Black)
		return;

	if(Parent->color == Red)
	{
		node Uncle;
		if(GrandParent->Lc == nullptr || GrandParent->Rc == nullptr) Uncle = nullptr;
		else Uncle = (GrandParent->Lc->data == Parent->data) ? GrandParent->Rc : GrandParent->Lc;
		bool Unclecolor = (Uncle == nullptr) ? Black : Uncle->color;
			
		if(Unclecolor == Red) 
			ReColoring(RBT,rootNode,GrandParent);
		else
			ReStructuring(RBT,rootNode,Parent,GrandParent);	
	}
}

void ReColoring(redblacktree& RBT,node& rootNode,node& grandParent)
{
	cout << "ReColoring" << endl;
	if(grandParent->Lc != nullptr) grandParent->Lc->color = Black;
	if(grandParent->Rc != nullptr) grandParent->Rc->color = Black;
	grandParent->color = Red;
	
	node greatGrandParent = GetParent(RBT->root,grandParent);
	if(greatGrandParent == nullptr) grandParent->color = Black;
	else 
	{
		if(greatGrandParent->color == Red) BalanceIngRBT(RBT,grandParent);
		else return;
	}
}


void RotateLL(redblacktree& RBT, node& rootNode)
{
	//cout << "LL" << endl;
	node rootNodeParent = GetParent(RBT->root, rootNode); //현재 노드의 부모 

	// 1.부모 노드를 좌측자식의 우측자식으로 연결한다.
	node newRootNode = rootNode->Lc;
	node newRootNodeRc = newRootNode->Rc;
	rootNode->Lc = nullptr;
	newRootNode->Rc = rootNode;

	if(rootNodeParent == nullptr)
	{
		rootNode->Lc = newRootNodeRc;
		RBT->root = newRootNode;
	}
	else
	{
		rootNode->Lc = newRootNodeRc;
		if (rootNodeParent->data < rootNode->data)
			rootNodeParent->Rc = newRootNode;
		else	
			rootNodeParent->Lc = newRootNode;
	} 
}

void RotateRR(redblacktree& RBT, node& rootNode)
{
	//cout << "RR" << endl;
	node rootNodeParent = GetParent(RBT->root, rootNode);
	
	// 1.부모 노드를 우측 자식노드의 좌측자식으로 연결한다.
	node newRootNode = rootNode->Rc;
	node newRootNodeLc = newRootNode->Lc;	
	rootNode->Rc = nullptr;
	newRootNode->Lc = rootNode;
	
	if(rootNodeParent == nullptr) 
	{	
		rootNode->Rc = newRootNodeLc;
		RBT->root = newRootNode;
	}
	else 
	{
		rootNode->Rc = newRootNodeLc;
		if (rootNodeParent->data < rootNode->data)
			rootNodeParent->Rc = newRootNode;
		else
			rootNodeParent->Lc = newRootNode;	
	}	
}

void RotateLR(redblacktree& RBT, node& parent, node& grandParent)
{
	//cout << "LR" << endl;
	RotateRR(RBT, parent);
	RotateLL(RBT, grandParent);
	return;
}

void RotateRL(redblacktree& RBT, node& parent, node& grandParent)
{
	//cout << "RL" << endl;
	RotateLL(RBT, parent);
	RotateRR(RBT, grandParent);
	return;
}

void SolveDoublyBlack(redblacktree& RBT,node& doublyNode,node& doublyParent,node& doublyBrother)
{
	if(doublyNode == RBT->root)
	{
		doublyNode->color = Black;
		return;
	}
	bool brotherColor;
	bool brotherRcColor;
	bool brotherLcColor;

	brotherColor = (doublyBrother == nullptr) ? 
				Black : ((doublyBrother->color == Black) ? Black : Red);
	brotherRcColor = (doublyBrother->Rc == nullptr) ? 
				Black : ((doublyBrother->Rc->color == Black) ? Black : Red);
	brotherLcColor = (doublyBrother->Lc == nullptr) ? 
				Black : ((doublyBrother->Lc->color == Black) ? Black : Red);
				
	if(brotherColor == Black)
	{
		if(doublyBrother == nullptr)
		{			
			doublyNode->color = Black;
			if(doublyParent->color == Red)
				doublyParent->color = Black;
			else
			{
				if(doublyParent == RBT->root)
				{	 
					doublyParent->color = Black;
					return; 
				}
				
				node parent = GetParent(RBT->root,doublyParent);
				if(parent->data < doublyParent->data)
					SolveDoublyBlack(RBT,doublyParent,parent,parent->Lc);
				else
					SolveDoublyBlack(RBT,doublyParent,parent,parent->Rc);
			}
			return;
		}
		
		// doublyblack 노드가 부모노드의 왼쪽에 있을때 
		if(doublyParent->data > doublyNode->data)
		{
			// case 4 더블리블랙에 형제의 오른쪽 자식이 Red일때 
			if(brotherRcColor == Red)
			{ 
				cout << "case4" << endl;
				if(doublyBrother->Lc != nullptr)
				{
					// 왼쪽 자식이 검정이면 doublyblack 아니면 black 
					if(doublyBrother->Lc->color == Red)
						doublyBrother->Lc->color = Black;
					else doublyBrother->Lc->color = DoublyBlack;
				}
				doublyBrother->Rc->color = Black;
				doublyBrother->color = doublyParent->color;
				doublyParent->color = Red;
				RotateRR(RBT,doublyParent);
				if(doublyParent->Lc->color == DoublyBlack)
					doublyParent->Lc->color = Black;
				if(doublyParent->Rc != nullptr)
				{
					if(doublyParent->Rc->color == DoublyBlack)
						doublyParent->Rc->color = Black;
					else doublyParent->Rc->color = Red;
				}
				doublyParent->color = Black;
			}
			// case 3 더블리블랙에 형제의 왼쪽 자식이 Red일때 
			else if(brotherLcColor == Red) 
			{
				cout << "case3" << endl;
				doublyBrother->Lc->color = Black;
				doublyBrother->color = Red;
				node brotherLc = doublyBrother->Lc;
				RotateLL(RBT,doublyBrother);
				SolveDoublyBlack(RBT,doublyNode,doublyParent,brotherLc);
			}
			// case 2 더블리블랙에 형제의 양쪽 자식 모두 Black일때 
			else
			{
				cout << "case2" << endl;
				doublyBrother->color = Red;
				doublyNode->color = Black;
				if(doublyParent->color == Red) 
					doublyParent->color = Black;
				else
				{
					doublyParent->color = DoublyBlack;
					if(RBT->root == doublyParent) 
						doublyParent->color = Black;
					else
					{
						node parent = GetParent(RBT->root,doublyParent);
						node brother = (parent->data < doublyParent->data) ? parent->Lc : parent->Rc;
						SolveDoublyBlack(RBT,doublyParent,parent,brother);
					}						
				}
			}
		}
		
		// doublyblack 노드가 부모노드의 오른쪽에 있을때 
		else
		{
			// case 4 더블리블랙에 형제의 왼쪽 자식이 Red일때 
			if(brotherLcColor == Red)
			{
				cout << "case4 - 좌우대칭" << endl;
				if(doublyBrother->Rc != nullptr)
				{
					if(doublyBrother->Rc->color == Red)
						doublyBrother->Rc->color = Black;
					else doublyBrother->Rc->color = DoublyBlack;
				}
				doublyBrother->Lc->color = Black;
				doublyBrother->color = doublyParent->color;
				doublyParent->color = Red;
				RotateLL(RBT,doublyParent);
	
				if(doublyParent->Rc->color == DoublyBlack)
					doublyParent->Rc->color = Black;
				if(doublyParent->Lc != nullptr)
				{
					if(doublyParent->Lc->color == DoublyBlack)
						doublyParent->Lc->color = Black;
					else doublyParent->Lc->color = Red;
				}
				doublyParent->color = Black;
			}
			// case 3 더블리블랙에 형제의 오른쪽 자식이 Red일때 
			else if(brotherRcColor == Red) 
			{
				cout << "case3 - 좌우대칭" << endl; 
				doublyBrother->Rc->color = Black;
				doublyBrother->color = Red;
				node brotherRc = doublyBrother->Rc;
				RotateRR(RBT,doublyBrother);
				SolveDoublyBlack(RBT,doublyNode,doublyParent,brotherRc);
			}
			// case 2 더블리블랙에 형제의 양쪽 자식 모두 Black일때 
			else
			{
				cout << "case2 - 좌우대칭" << endl; 
				doublyBrother->color = Red;
				doublyNode->color = Black;
				if(doublyParent->color == Red) 
					doublyParent->color = Black;
				else
				{
					doublyParent->color = DoublyBlack;
					if(RBT->root == doublyParent) 
						doublyParent->color = Black;
					else
					{
						node parent = GetParent(RBT->root,doublyParent);
						node brother = (parent->data < doublyParent->data) ? parent->Lc : parent->Rc;
						SolveDoublyBlack(RBT,doublyParent,parent,brother);
					}						
				}
					
			}
		}
	}
	
	else
	{
		if(doublyParent->data > doublyNode->data)
		{
			cout << "case1" << endl;
			doublyParent->color = Red;
			doublyBrother->color = Black;
			RotateRR(RBT,doublyParent);
			SolveDoublyBlack(RBT,doublyNode,doublyParent,doublyParent->Rc);
		}
		else
		{
			cout << "case1 - 좌우대칭" << endl;
			doublyParent->color = Red;
			doublyBrother->color = Black;
			RotateLL(RBT,doublyParent);
			SolveDoublyBlack(RBT,doublyNode,doublyParent,doublyParent->Lc);
		}
	}
}

void ReStructuring(redblacktree& RBT,node& rootNode,node& parent,node& grandParent)
{
	//cout << "ReStructuring" << endl;
	grandParent->color = Red;
	if(grandParent->data > parent->data)
	{
		// parent가 중간값일때 
		if(parent->data > rootNode->data)
		{
			parent->color = Black;
			rootNode->color = Red;
			RotateLL(RBT,grandParent);
		}
		else
		{
			parent->color = Red;
			rootNode->color = Black;
			RotateLR(RBT,parent,grandParent);
		}
	}
	else
	{
		if(parent->data < rootNode->data)
		{
			parent->color = Black;
			rootNode->color = Red;
			RotateRR(RBT,grandParent);
		}
		else
		{
			parent->color = Red;
			rootNode->color = Black;
			RotateRL(RBT,parent,grandParent);
		}
	}
}


void InsertNode(node& rootNode,node& newNode)
{
	if (rootNode == nullptr)
		rootNode = newNode;
	else if (rootNode->data < newNode->data) InsertNode(rootNode->Rc, newNode);
	else InsertNode(rootNode->Lc, newNode);
}

node SearchNode(node& rootNode, int data)
{
	node result = nullptr;
	if (rootNode == nullptr) return nullptr;
	else if (rootNode->data == data) return rootNode;
	else if (rootNode->data < data) result = SearchNode(rootNode->Rc, data);
	else result = SearchNode(rootNode->Lc, data);
	return result;
}

node DeleteNode(node& rootNode,int data)
{
	if(rootNode == nullptr) 
		return nullptr;
		
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

node GetParent(node& rootNode, node& TargetNode)
{
	node result = nullptr;
	if (rootNode == nullptr) return nullptr; 
	else if (rootNode->Lc == TargetNode || rootNode->Rc == TargetNode) return rootNode;
	else if (rootNode->data < TargetNode->data) result = GetParent(rootNode->Rc, TargetNode);
	else result = GetParent(rootNode->Lc, TargetNode);
	return result;
}

node GetRightSubTreeMinNode(node& rootNode)
{
	node RightSubTree_MinChild = rootNode->Rc;
	while (RightSubTree_MinChild->Lc != nullptr)
		RightSubTree_MinChild = RightSubTree_MinChild->Lc;
	return RightSubTree_MinChild;
}

void Print_RedBlackTree(node root,int choice)
{
	if (root == nullptr)
		return;
	string str;
	if(root->color)str = "Black";
	else str = "Red"; 
	switch(choice)
	{
		case 1: // 전위 순위 preorder
			cout << root->data << " " << str << endl;
			Print_RedBlackTree(root->Lc,choice);
			Print_RedBlackTree(root->Rc,choice);
			break;
		case 2: // 중위 순위 inorder 
			Print_RedBlackTree(root->Lc,choice);
			cout << root->data << " ";
			Print_RedBlackTree(root->Rc,choice);
			break;
		case 3: // 후위 순위 postorder 
			Print_RedBlackTree(root->Lc,choice);
			Print_RedBlackTree(root->Rc,choice);
			cout << root->data << " ";
			break;
		default:
			printf("wrong choice!");
			break;
	}
	return;
}

void DeleteRedBlackTree(node rootNode)
{
	if(rootNode == nullptr) return; 
	DeleteRedBlackTree(rootNode->Lc);
	DeleteRedBlackTree(rootNode->Rc);
	rootNode->Lc = nullptr;
	rootNode->Rc = nullptr;
	delete rootNode;
}

void PrintMenu()
{
	printf("	------------Red-BlackTree----------\n");
	printf("	============Menu============\n");
	printf("	1. Add Data\n");
	printf("	2. Serch Data\n");
	printf("	3. Delete Data.\n");
	printf("	4. Print_Red-BlackTree.\n");
	printf("	5. Print_Menu.\n");
	printf("	6. clear Display.\n");
	printf("	7. clear Red-BlackTree.\n");
	printf("	8. Exit.\n");
	printf("	============================\n");
}



