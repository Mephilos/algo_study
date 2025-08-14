#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int arrA[N][M];
    int arrB[N][M];
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arrA[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arrB[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arrA[i][j] + arrB[i][j] << ' ';
        }
        cout << '\n';
    }
}