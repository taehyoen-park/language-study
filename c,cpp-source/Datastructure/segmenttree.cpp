#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
#include<windows.h>
#include<limits.h>
#include<algorithm>
#define StartNodeNumber 1

/*
	C++언어로 segmenttree구현해보기
	만든사람: taehyeon-park
	깃 허브 :  https://github.com/taehyoen-park/language-study/blob/master/c%2Ccpp-source/Datastructure/segmenttree.cpp
*/

using namespace std;
typedef long long ll;

const ll Max = LLONG_MIN;
const ll Min = LLONG_MAX;
bool Power = true;
ll ArraySize = 0, Choice;
vector<ll> segmentTree;
vector<ll> segmentTreeMax;
vector<ll> segmentTreeMin;
vector<ll> arr;

void InputData();
void PrintMenu();
void MakeQuerySegmentTree(bool isMAX);
void PrintArray();
void PrintSegmentTree();
void UpdateTreeSize();
void QueryRequest();
bool CheckSegmentTree();

ll MakeSegmentTree(ll node, ll start, ll end)
{
	if (start == end) return segmentTree[node] = arr[start];

	ll mid = (start + end) / 2;
	ll leftChild = (node*2);
	ll rightChild = leftChild + 1;
	ll leftResult = MakeSegmentTree(leftChild, start, mid);
	ll rightResult = MakeSegmentTree(rightChild, mid + 1, end);
	ll parent = leftResult + rightResult;
	return segmentTree[node] = parent;
}

void MakeQuerySegmentTree(int node, int start, int end, bool isMax)
{
    if(start == end) 
	{
        if (isMax) segmentTreeMax[node] = arr[start];
        else segmentTreeMin[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    ll leftChild = node*2;
	ll rightChild = leftChild + 1;
    MakeQuerySegmentTree(leftChild, start, mid, isMax);
    MakeQuerySegmentTree(rightChild, mid+1, end, isMax);

    if (isMax) segmentTreeMax[node] = max(segmentTreeMax[leftChild], segmentTreeMax[rightChild]);
    else segmentTreeMin[node] = min(segmentTreeMin[leftChild], segmentTreeMin[rightChild]);
}

ll Getsum(const ll node,const ll start,const ll end, ll LeftBound, ll RightBound)
{
	if (start > RightBound || end < LeftBound) return 0;
	if (start >= LeftBound && end <= RightBound) return segmentTree[node];

	ll mid = (start + end) / 2;
	ll leftChild = node*2;
	ll rightChild = leftChild + 1;
	ll leftResult = Getsum(leftChild, start, mid, LeftBound, RightBound);
	ll rightResult = Getsum(rightChild, mid + 1, end, LeftBound, RightBound);

	return leftResult + rightResult;
}

ll Query(ll node, ll start, ll end, ll LeftBound, ll RightBound, bool isMax)
{
	if (start > RightBound || end < LeftBound)
		return isMax ? Max : Min;

	if (start >= LeftBound && end <= RightBound)
		return isMax ? segmentTreeMax[node] : segmentTreeMin[node];

	ll mid = (start + end) / 2;
	ll leftChild = node*2;
	ll rightChild = leftChild + 1;
	ll leftResult = Query(leftChild, start, mid, LeftBound, RightBound, isMax);
	ll rightResult = Query(rightChild, mid + 1, end, LeftBound, RightBound, isMax);

	return isMax ? max(leftResult, rightResult) : min(leftResult, rightResult);
}

void Update_segmentTree(ll node,ll start,ll end,ll index, ll diff)
{
	if (start > index || end < index) return;
	segmentTree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		ll leftChild = node*2;
		ll rightChild = leftChild + 1;
		Update_segmentTree(leftChild, start, mid, index, diff);
		Update_segmentTree(rightChild, mid + 1, end, index, diff);
	}
}

int main()
{
	while (Power)
	{
		PrintMenu();
		printf("select---> ");
		scanf("%lld", &Choice);
		switch (Choice)
		{
		case 1:
			InputData();
			UpdateTreeSize();
			MakeSegmentTree(StartNodeNumber, 0, ArraySize - 1);
			break;
		case 2:
			if(!CheckSegmentTree()) continue;
			ll idx, val;
			printf("Enter the index of the element you want to change(range: %lld ~ %lld): ",1,ArraySize);
			scanf("%lld", &idx);
			printf("Enter the new value for the element: ");
			scanf("%lld", &val);
			Update_segmentTree(StartNodeNumber, 0, ArraySize - 1, idx-1, val - arr[idx-1]);
			break;
		case 3:
			if(!CheckSegmentTree()) continue;
			printf("1.Find the maximum value\n");
			printf("2.Find the minimum value\n");
			printf("3.Calculate the sum of the given range\n");
			QueryRequest();
			break;
		case 4:
			if(!CheckSegmentTree()) continue;
			PrintSegmentTree();
			break;
		case 5:
			system("cls");
			break;
		case 6:
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

void PrintMenu()
{
	printf("	============Menu============\n");
	printf("	1. Add Data\n");
	printf("	2. Update Data.\n");
	printf("	3. Query request.\n");
	printf("	4. Print_segmentTree.\n");
	printf("	5. clear Display.\n");
	printf("	6. Exit.\n");
}

void PrintArray()
{
	for (int i = 0; i < ArraySize; i++)
		printf("%d.Data:%lld ", i + 1, arr[i]);
	printf("\n");
}

void PrintSegmentTree()
{
	for (auto i = segmentTree.begin()+1; i != segmentTree.end(); i++) {
		printf("%d.Data:%lld ", (i - segmentTree.begin()) + 1, (*i));
		if ((i - segmentTree.begin() + 1) % 6 == 0) printf("\n");
	}
	printf("\n");
}

void InputData()
{
	ll data, DataCount;
	cout << "How many data do you want to input? ";
	scanf("%lld", &DataCount);
	printf("Data Input : ");
	for (int i = 0; i < DataCount; i++)
	{
		scanf("%lld", &data);
		arr.emplace_back(data);
		ArraySize++;
	}
}

bool CheckSegmentTree()
{
	if(segmentTree.empty()) {
		printf("segmentTree is empty!\n");
		return false;
	}
	else return true;
}

void UpdateTreeSize()
{
	int tree_height = ceil(log2(ArraySize));
	int tree_size = (1 << tree_height + 1);
	segmentTree.resize(tree_size);
}

// 구간합,구간의 최솟값,구간의 최댓값을 요청하는 함수 
void QueryRequest()
{
	ll i, Sum = 0, leftbound, rightbound;
	ll tree_height = ceil(log2(ArraySize));
	ll tree_size = (1 << tree_height + 1);
	bool isMax = true,isMin = false;
	
	
	//1.Find the maximum value
	//2.Find the minimum value
	//3.Calculate the sum of the given range
	printf("select---> ");
	scanf("%lld", &i);
	printf("Please enter the range of the interval. range(%d~%lld)\n", 1,ArraySize);
	
	printf("Start Index : ");
	scanf("%lld", &leftbound);
	
	printf("End Index : ");
	scanf("%lld", &rightbound);

	switch (i)
	{
	case 1:
		ll Maxnum;
		segmentTreeMax.resize(tree_size);
		MakeQuerySegmentTree(StartNodeNumber,0,ArraySize-1,isMax);
		Maxnum = Query(StartNodeNumber, 0, ArraySize - 1, leftbound - 1, rightbound - 1, isMax);
		printf("Maximum value : %lld\n", Maxnum);
		segmentTreeMax.clear();
		break;
	case 2:
		ll Minnum;
		segmentTreeMin.resize(tree_size);
		MakeQuerySegmentTree(StartNodeNumber,0,ArraySize-1,isMin);
		Minnum = Query(StartNodeNumber, 0, ArraySize - 1, leftbound - 1, rightbound - 1, isMin);
		printf("Minimum value : %lld\n", Minnum);
		segmentTreeMin.clear();
		break;
	case 3:
		Sum = Getsum(StartNodeNumber,0,ArraySize - 1, leftbound - 1, rightbound - 1);
		printf("The sum of the range is : %lld\n", Sum);
		break;
	default:
		printf("Wrong Choice");
		fflush(stdin);
		break;
	}
}
