#include<iostream>
#include<vector>
#define Max 9

using namespace std;

int main()
{
    int graph[Max][Max];

    for(int i = 0; i < Max-1; i++){
        for(int j = 0; j < Max-1; j++){
            graph[i][j] = 0;
        }
    }

    cout << "-----------����� �׷���----------" << endl;
    cout << "(���� ��ķ� �׷��� ǥ���ϱ�)" << endl;

    cout << "1�� 2�� ����" << endl;
    graph[1][2] = 1;

    cout << "3�� 5�� ����" << endl;
    graph[3][5] = 1;

    cout << "4�� 7�� ����" << endl;
    graph[4][7] = 1;


    for(int i = 1; i < Max-1; i++){
        for(int j = 1; j < Max-1; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}