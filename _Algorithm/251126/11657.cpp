#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;
struct Edge
{
    int u;
    int v;
    int w;
};
vector<long long> dist;
vector<Edge> edges;
int N, M;

bool BellmanFord(int start)
{
    dist[start] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] == INF)
            {
                continue;
            }

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dist[u] == INF)
        {
            continue;
        }

        if (dist[v] > dist[u] + w)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // edges.resize(M + 1); // push_back 쓰자... 인덱스 관리 귀찮다...
    dist.resize(N + 1, INF);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    bool NegativeCycle = BellmanFord(1);

    if (NegativeCycle)
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
