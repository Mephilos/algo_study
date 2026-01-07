#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int S;
    int E;
    int T;
};

vector<Edge> edges;
vector<long long> dist;
const long long INF = 1e18;
int T, N, M, W;

bool BellmanFord()
{
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (auto &edge : edges)
        {
            int s = edge.S;
            int e = edge.E;
            int t = edge.T;

            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
            }
        }
    }
    for (auto &edge : edges)
    {
        int s = edge.S;
        int e = edge.E;
        int t = edge.T;

        if (dist[e] > dist[s] + t)
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
        bool negative = BellmanFord();

        if (negative)
        {
            cout << "YES" << '\n';
        }
        else
            cout << "NO" << '\n';
    }
}