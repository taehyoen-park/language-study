#pragma once
#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

class Node;
typedef Node* node;
typedef int Color;

enum eColor {
	Red,
	Black,
	DoublyBlack
};

class Node {
public:
	node Rc;
	node Lc;
	int data;
	Color color;
	Node(int data) :data(data), color(Red), Rc(nullptr), Lc(nullptr) {};
};

class RedBlackTree;
typedef RedBlackTree* redblacktree;
class RedBlackTree {
private:
	node root;
	int treeSize;
	void InsertNode(node& rootNode, node& newNode);
	node DeleteNode(node& rootNode, int data);
	node SearchNode(node& rootNode, int data);
	void BalanceIngRBT(redblacktree& RBT, node& rootNode);
	void RotateLL(redblacktree& RBT, node& rootNode);
	void RotateRR(redblacktree& RBT, node& rootNode);
	void RotateLR(redblacktree& RBT, node& parent, node& grandParent);
	void RotateRL(redblacktree& RBT, node& parent, node& grandParent);
	void ReColoring(redblacktree& RBT, node& rootNode, node& grandParent);
	void ReStructuring(redblacktree& RBT, node& rootNode, node& parent, node& grandParent);
	node GetParent(node& rootNode, node& TargetNode);
	node GetRightSubTreeMinNode(node& rootNode);
	void DeleteRedBlackTree(node rootNode);
	void SolveDoublyBlack(redblacktree& RBT, node& doublyNode, node& doublyParent, node& doublyBrother);
	void PrintRedBlackTree(node root, int choice);

public:
	RedBlackTree() : root(nullptr), treeSize(0) {};
	void Print(int choice);
	void Insert(int inputData);
	void Delete(int inputData);
	void Clear();
	Node* find(int inputData);
	int size() const;
};
