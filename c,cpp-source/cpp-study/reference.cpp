#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	cout << a << endl; // main�� �������� a ���; 
	
	
	int &ref_a = a;//������ ����(reference)
	cout << ref_a << endl; //ref_a ��� 
	/* 
	ref_a�� a�� �������̴� �̸��� a�� �Ǵٸ� �̸��̶�� ���̴�.
	ref_a�� � �۾��� �����ϵ� a�� �����ϴ� �Ͱ� �Ȱ���.
	ref_a�� �޸𸮿� ������ ������ �ʴ´� a�� �ٸ� �̸��� ���̴�.
	*/
	a += 10;
	cout << a << endl; // 20
	
	ref_a += 10;
	cout << ref_a << endl;//30;
	
 	int b = 20;
 	/*
	int ref_b; <- ������ �ַ� �߻� reference�� ������ �ٸ��̸��̴�.
	�����Ҷ� ������ �ʱ�ȭ ���� ������ ������ ���µ� �̸��� �޷��ִ� ���̴�.
	�̸� ��۸� ���۷������ �Ѵ�.
	*/
	int c[10];
	int (&ref_c)[10] = c; //reference�迭
	
	for(int i = 0; i < 10; i++)
		c[i] = i+1;
	
	for(int i = 0; i < 10; i++)
		cout << ref_c[i] << " ";  // �迭 ��� 
	
	int d = 10;
	//int &ref_d = fuc(d); �ַ�
	/*
	�����ڸ� ��ȯ�ϴ� �Լ��� ������ �� �Լ��� ������ ������� ������
	�̸��� ���Եȴ�. (��۸� ���۷���)
	*/
	 
	return 0;
} 
