#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	map<int,string> myMap;
	
	myMap.insert(make_pair(1,"apple"));
	myMap.insert({2,"bananan"});
	
	for(auto i = myMap.begin(); i != myMap.end(); i++)
	{
		cout << "  Key : " << i->first << "  Value : " << i->second << endl;
	}
	
	return 0;
}
