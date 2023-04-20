#include<iostream>
#include<vector>
#include<stack>
#define Max 10001

using namespace std;

int id,d[Max]; //�������̵� �Ҵ�,�湮ó��  
bool finished[Max]; // �������̵� ����ó���� ���´��� üũ 
vector<int> a[Max]; //�������� 
vector<vector<int>> scc; //���� �����ҳ����� �迭 
stack<int>s;

// �� ������ ���� ��ŭ ����ȴ�. 
int dfs(int x){
	d[x] = ++id; 
	s.push(x);  
	
	int parent = d[x]; 
	for(unsigned int i = 0 ; i < a[x].size(); i++){
		int index = a[x][i];
		if(d[index] == 0) parent = min(parent,dfs(index));
		else if(!finished[index])parent = min(parent,d[index]);
	}
	
	if(parent == d[x]){
		vector<int> SCC;
		while(1){
			int t = s.top();
			s.pop();
			SCC.push_back(t);
			finished[t] = true;
			if(t == x)break;
		}		
		scc.push_back(SCC);
	}
	
	return parent;
}

int main()
{
	int v = 10;
	
	a[1].push_back(6);
	a[1].push_back(5);
	a[3].push_back(4);
	a[6].push_back(10);
	a[9].push_back(7);
//	a[5].push_back(6);
//	a[6].push_back(4);
	
	for(int i = 1; i <= v; i++)
		if(d[i] == 0) dfs(i);	
	
	cout << "scc�� ���� : " << scc.size() << endl;
	for(unsigned int i = 0; i < scc.size();i++){
		cout << i+1 << "��° scc : ";
		for(unsigned int j = 0; j < scc[i].size();j++){
			cout << scc[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
