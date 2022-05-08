#include<iostream>
#include<vector>
#include<stack>
#define Max 10001

using namespace std;

int id,d[Max];
bool finished[Max];
vector<int> a[Max];
vector<vector<int>> scc;
stack<int>s;

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
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	
	a[4].push_back(2);
	a[4].push_back(5);
	
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	
	for(int i = 1; i <= v; i++)
		if(d[i] == 0) dfs(i);	
	
	cout << "sccÀÇ °¹¼ö : " << scc.size() << endl;
	for(unsigned int i = 0; i < scc.size();i++){
		cout << i+1 << "¹øÂ° scc : ";
		for(unsigned int j = 0; j < scc[i].size();j++){
			cout << scc[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
