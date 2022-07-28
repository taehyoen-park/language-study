#include<iostream>
#include<vector>

using namespace std;

typedef long long int ull;
bool treecut(ull x);
vector<ull> tree;

ull binary_search(ull start,ull end,ull x)
{
	ull middle;
	while((start + 1) < end)
	{
		middle = (start+end)/2;
		if(treecut(middle)) 
			start = middle+1;
		else 
			end = middle-1;
	}
	return start;
}

bool treecut(ull x)
{
	ull sum = 0;
	for(unsigned int i = 0; i < tree.size(); i++){
		if(tree[i] > x) sum = sum + (tree[i]-x);
	}
	return sum >= x;
}
int main()
{
	ull n,m;
	scanf("%lld %lld",&n,&m);
	
	ull Max = -1;
	for(ull i = 0; i < n; i++)
	{
		ull k;
		scanf("%lld",&k);
		tree.push_back(k);
		Max = max(Max,k);
	}
	if(m == 1)
	{
		printf("%lld",Max-1);
		return 0;
	}
	if(n == 1)
	{
		printf("%lld",tree[0]- m);
		return 0;
	}
	
	ull result;
	result = binary_search(0,Max,m);
	printf("%lld",result);
	
	return 0;
}
