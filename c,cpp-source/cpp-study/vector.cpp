#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int>v; //���ͼ���
	vector<int>v1(3); // 3�� ���� �����Ҵ� ���� 0���� �ʱ�ȭ
	vector<int>v2(3,10);//3�� ���� �����Ҵ��� ���� 10���� �ʱ�ȭ
	vector<int>v3 = {10,20,30};//3�� ���� �����Ҵ��� 10,20,30���� �ʱ�ȭ
	vector<int>::iterator iter;//�ݺ��� iterator 
	vector<int>v4[] = {{1,2},{5,7}};
	
	
	//.reserve�� ���� �̸� 100��ŭ �����Ҵ� 
	v.reserve(100);
	
	//.size() ������ ũ�⸦ ��ȯ�Ѵ�.
	// .capacity()�Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�. 
	cout << "v�� ������� " << v.size() << "�Դϴ�." << endl;
	cout << "v1�� ������� " << v1.size() << "�Դϴ�." << endl;
	cout << "v2�� ������� " << v2.size() << "�Դϴ�." << endl;
	cout << "v3�� ������� " << v3.size() << "�Դϴ�." << endl;
	cout << "v4�� ������� " << v4[0].size() << "�Դϴ�." << endl;
	cout << "v1�� �Ҵ�� ������ " << v1.capacity() << endl << endl; 
	
	//.push_back(n) ������ ������ ������ n�� �Ҵ� 
	v.push_back(10);
	v.push_back(20);
	cout << "v�� ũ��" << v.size() << endl;
	
	//.at(i),[i]  i��° ��ҿ� ���� at�� ������ �˻��Ͽ� ������ ������ ����ó���� �Ѵ�. 
	cout << "v�� 0��° ����" << v.at(0) << " v�� 1��° ����" << v[1] << endl; 
	
	//.pop_back() ������ ������ ������ ���� ����
	cout << "v�� pop_back()���� ���� ����" << endl; 
	v.pop_back();
	v.pop_back();
	cout << "v�� ũ��" << v.size() << endl << endl;

	cout << "v���Ϳ� 10~80���� �Ҵ� �׸��� ���" << endl; 
	for(int i = 0; i < 8; i++)
		v.push_back((i+1)*10);
	for(int i = 0 ;i < 8; i++)
		cout << v[i] << " ";
	cout << endl;
	
	//.insert(i,n) i��°�� n���� �����Ѵ�. Ȥ�� insert(i,x,n) x���� n���� ���� �� �ִ�. 
	v.insert(v.begin()+3,100);
	cout << v[3] << endl; 
	v.insert(v.begin()+5,5,3);
	for(int i = 0; i < 14; i++)
		cout << v[i] << " ";
	cout << endl;
	
	//.cmpty() ���Ͱ� ����ִ��� Ȯ���Ѵ�.
	if(!v.empty())
		cout << "������� �ʴ�." << endl;
	else
		cout << "����ִ�."  << endl;
	
	//.erase(i) , .erase(i,j) i���� Ȥ�� i����j������ ���Ҹ� �����մϴ�.
	v.erase(v.begin()+5,v.begin()+9);
	cout << "erase�Լ��� 5����9��°���� ���� ����" << endl;
	for(int i = 0 ;i < 10; i++)
		cout << v[i] << " ";
	cout << endl;
	
	// .swap�� ����� v�� v1�� �ٲ۴� 
	v.swap(v1);
	
	
	iter = v1.begin();
	cout << *iter << endl; // ���� ���� 
	for(iter = v1.begin(); iter < v1.end();iter++)
		cout << *iter << " ";
		
	// .clear�� ����� v�� ���Ҹ� �������
	v.clear();
	cout << v.size() << endl; 

	return 0;
}
