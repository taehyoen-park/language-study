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

    cout << "-----------양방향 그래프----------" << endl;
    cout << "(인정 행렬로 그래프 표현하기)" << endl;

    cout << "1과 2를 연결" << endl;
    graph[1][2] = 1;

    cout << "3과 5를 연결" << endl;
    graph[3][5] = 1;

    cout << "4와 7를 연결" << endl;
    graph[4][7] = 1;


    for(int i = 1; i < Max-1; i++){
        for(int j = 1; j < Max-1; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}