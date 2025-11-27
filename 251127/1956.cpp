#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n';

vector<vector<int>> dist;
int V, E;
const int INF = 1e9;

void floydWarshell()
{
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
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

    cin >> V >> E;

    dist.resize(V + 1, vector<int>(V + 1, INF));

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

    floydWarshell();
    int sum = INF;

    for (int i = 1; i <= V; i++)
    {
        sum = min(sum, dist[i][i]);
    }
    if (sum == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << sum << endl;
    }
}