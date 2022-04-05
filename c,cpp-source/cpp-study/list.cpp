#include<iostream>
#include<list>
#define n 10

using namespace std;

int main()
{
	list<int>it(1); // ����ִ� ����Ʈ ����
	list<int>it2(5); //������ 5��ŭ �Ҵ�� ����Ʈ ���� default���� 0�̴�.
	list<int>it3(3,2); // 2������ 3���� �Ҵ�� ����Ʈ ����
	list<int>::iterator iter;

	//�������� ���� k�� �����մϴ�. 
	it.push_front(1);
	
	//�������� ���� k�� �����մϴ�. 
	it.push_back(2);

	/*
	��� 	 
	it.begin() �� ���� ���Ҹ� ����Ű�� iterator�� ��ȯ�մϴ�.
	it.end()	�� ���� ���Ҹ� ����Ű�� iterator�� ��ȯ�մϴ�.
	*/	
	for(iter = it.begin(); iter != it.end();iter++)
		cout << *iter << " ";
	cout << endl;
	
	
	//�� ���� ���Ҹ� ��ȯ,�����Ѵ�. 
	cout <<	"(�� ���� ���� ��ȯ).front() = " << it.front() << endl;
	
	//�� ���� ���Ҹ� ��ȯ,���� �մϴ�. 
	cout << "(�� ���� ���� ��ȯ).back() = " << it.back() << endl;
	
	//�� ������ ���Ҹ� �����մϴ�. 
	it.pop_back();
	
	//�� �� ���Ҹ� �����մϴ�.
	it.pop_front();
		
//	iter = it.begin(); 
	//iter�� ����Ű�� ��ġ�� ���� k�� �����մϴ�. �� �Ŀ� iterator�� ��ȯ�Ѵ�. 
	iter = it.insert(iter,100);
	cout << *(iter) << endl;
	
	//iterator�� ����Ű�� ���Ҹ� ���� 
//	it.erase(iter);
//	//������ ������ ��ȯ�մϴ�. 
//	it.size();
//	//k�� ���� ���Ҹ� ��� �����մϴ� 
//	it.remove();
//	//���� �����ڿ� �ش��ϴ� ���Ҹ� ��� �����մϴ�. 
//	it.remove_if();
//	//���ҵ��� �������� �������ϴ�. 
//	it.reverse();
//	//��� ���Ҹ� ������������ �����մϴ�. 
//	it.sort();
//	//����Ʈ 2���� ���� ��ȯ�մϴ�. 
//	it.swap();
//	//������ ���Ұ� ������ �����ϰ� ����ϴ�. 
//	it.unique();
//	//2���� ����Ʈ�� �պ� �����մϴ�. default�� ���������� 
//	it.merge();
// .assign(i,n)n���� �ʱ�ȭ�� i�� ���Ҹ� �Ҵ��Ѵ�. 
	it.assign(3,5);
	
	 
	return 0;
}
