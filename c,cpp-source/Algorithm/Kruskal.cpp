#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//크루스칼 알고리즘 

//부모 노드를 찾는 함수 
int getParent(int parent[],int x)
{
	if(parent[x] == x)return x;
	return parent[x] = getParent(parent,parent[x]);
	
}

//두 부모 노드를 합치는 함수 
void unionParent(int parent[],int a,int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b)parent[b] = a;
	else parent[a] = b;
}

//같은 부모를 가지는지 확인 
int findParent(int parent[],int a,int b)
{
	a = getParent(parent,a);
	b = getParent(parent,b);
	if(a == b )return 1;
	return 0;
}

//간선 클래스 선언 
class Edge{
public:
	int node[2];
	int distance;
	Edge(int a,int b,int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator<(Edge &edge){
		return this->distance < edge.distance;
	}
};
int main()
{
	int n = 7;
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12));
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(1,5,17));
	v.push_back(Edge(2,4,24));
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13));
	v.push_back(Edge(5,6,45));
	v.push_back(Edge(5,7,73));
	
	sort(v.begin(),v.end());
	
	for(unsigned int i = 0; i < v.size();i++){
		cout << v[i].distance << " ";
	}
	cout << endl;
	int parent[n+1];
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	int sum = 0;
	for(unsigned int i = 0; i < v.size();i++)
	{
		if(!findParent(parent, v[i].node[0], v[i].node[1])){
			sum += v[i].distance;
			unionParent(parent, v[i].node[0], v[i].node[1]);
		}
	}
	cout << sum << "\n";
	
	
	return 0;
}
