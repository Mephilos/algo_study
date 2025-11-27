#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n';

vector<vector<int>> dist;
int n, m;
const int INF = 1e9;

void floydWarshell()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    dist.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }
    floydWarshell();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << dist[i][j] << ' ';
            }
        }
        cout << endl;
    }
}