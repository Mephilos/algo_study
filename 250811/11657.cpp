#include <iostream>
#include <vector>
#include <limits>
#include <tuple>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int N, M;
vector<tuple<int, int, int>> edges;
long long dist[501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edges.emplace_back(A, B, C);
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }
    dist[1] = 0;

    bool hasNegativeCycle = false;

    for (int i = 1; i <= N; i++)
    {
        for (const auto& edge : edges)
        {
            int from, to, cost;
            tie(from, to, cost) = edge;
            
            if (dist[from] != INF && dist[from] + cost < dist[to])
            {
                dist[to] = dist[from] + cost;
                if (i == N)
                {
                    hasNegativeCycle = true;
                }
            }
        }
    }
    if (hasNegativeCycle)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == INF)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << dist[i] << '\n';
            }
        }
    }
}