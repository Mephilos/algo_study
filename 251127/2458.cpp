#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n';

vector<vector<bool>> dist;
int N, M;

void floydWarshell()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j])
                    continue;
                if (dist[i][k] && dist[k][j])
                {
                    dist[i][j] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    dist.resize(N + 1, vector<bool>(N + 1, false));
    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = true;
    }

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = true;
    }

    floydWarshell();

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int knowCnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] || dist[j][i])
            {
                knowCnt++;
            }
        }
        if (knowCnt == N)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}