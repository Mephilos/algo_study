#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> jip;
vector<vector<int>> danji;
vector<int> danjiCounter;
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int danjiNum = 1;

void DFS(int staR, int staC)
{
    danji[staR][staC] = danjiNum;
    danjiCounter.push_back(danjiNum);
    for (int i = 0; i < 4; i++)
    {
        int nr = staR + dr[i];
        int nc = staC + dc[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        {
            continue;
        }
        if (jip[nr][nc] == '1' && danji[nr][nc] == 0)
        {
            DFS(nr, nc);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    jip.resize(N);
    danji.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> jip[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (jip[i][j] == '1' && danji[i][j] == 0)
            {
                DFS(i, j);
                danjiNum++;
            }
        }
    }

    cout << danjiNum - 1 << '\n';
    vector<int> ssibal;
    for (int i = 1; i < danjiNum; i++)
    {
        int count = 0;
        for (int k : danjiCounter)
        {
            if (k == i)
            {
                count++;
            }
        }
        ssibal.push_back(count);
    }
    sort(ssibal.begin(), ssibal.end());

    for (int i : ssibal)
    {
        cout << i << '\n';
    }
}