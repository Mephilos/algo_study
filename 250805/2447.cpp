// 별 찍기 10 골드5

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> vec;

void func(int N, int x, int y)
{
    if ((x / N) % 3 == 1 && (y / N) % 3 == 1)
    {
        return;
    }

    if (N == 1)
    {
        vec[y][x] = '*';
        return;
    }

    int next_N = N / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            func(next_N, x + j * next_N, y + i * next_N);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vec.assign(N, vector<char>(N, ' '));

    func(N, 0, 0);

    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << vec[i][j];
        }
        cout << '\n';
    }
}