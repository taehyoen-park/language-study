#include<iostream>
#include<vector>
#include<stack>
#define Max 10001

using namespace std;

int id,d[Max]; //고유아이디 할당,방문처리  
bool finished[Max]; // 고유아이디가 연결처리를 끝냈는지 체크 
vector<int> a[Max]; //연결정보 
vector<vector<int>> scc; //강한 연결요소끼리의 배열 
stack<int>s;

// 총 점점의 갯수 만큼 실행된다. 
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
	
	cout << "scc의 갯수 : " << scc.size() << endl;
	for(unsigned int i = 0; i < scc.size();i++){
		cout << i+1 << "번째 scc : ";
		for(unsigned int j = 0; j < scc[i].size();j++){
			cout << scc[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
