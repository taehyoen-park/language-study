#include<iostream>
#include<vector>
#include<queue>
#define Max 10

using namespace std;

int n, indegree[Max];
vector<int> a[Max];

void topologySort(){
	int result[Max];
	queue<int> q;
	
	for(int i = 1 ; i <= n; i++)
		if(indegree[i] == 0) q.push(i);
	
	for(int i = 1; i <= n; i++){
		if(q.empty()){
			cout << "사이클이 발생했습니다." << endl; 
			return;
		}
		int x = q.front();
		result[i] = x;
		q.pop();
		for(unsigned int i = 0; i < a[x].size(); i++){
			int index = a[x][i];
			indegree[index]--;
			if(indegree[index] == 0)
				q.push(index);
		}
	}
	
	for(int i = 1; i <= n; i++)
		cout << result[i] << " ";
}
int main()
{
	n = 7;
	a[1].push_back(2);
	indegree[2]++;
	a[1].push_back(5);
	indegree[5]++;
	a[2].push_back(3);
	indegree[3]++;
	a[3].push_back(4);
	indegree[4]++;
	a[4].push_back(6);
	indegree[6]++;
	a[5].push_back(6);
	indegree[6]++;
	a[6].push_back(7);
	indegree[7]++;
	topologySort();
	return 0;
}
