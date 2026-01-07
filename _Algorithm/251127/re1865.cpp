#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
#define endl '\n';

struct edge
{
    int S;
    int E;
    int T;
};
vector<edge> edges;
vector<LL> dist;
int T, N, M, W;
const LL INF = 1e18;

bool BellmanFord()
{
    dist[1] = 0;

    for (int i = 1; i < N - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge.S;
            int v = edge.E;
            int w = edge.T;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto &edge : edges)
    {
        int u = edge.S;
        int v = edge.E;
        int w = edge.T;

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

    cin >> T;

    while (T-- > 0)
    {
        cin >> N >> M >> W;

        edges.clear();
        dist.clear();
        dist.resize(N + 1, INF);
        for (int i = 0; i < M; i++)
        {
            int s, e, t;

            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for (int i = 0; i < W; i++)
        {
            int s, e, t;

            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        bool flag = BellmanFord();

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}