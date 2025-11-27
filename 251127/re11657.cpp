#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

#define endl '\n';
struct edge
{
    int A;
    int B;
    int C;
};

vector<edge> edges;
vector<LL> dist;

const LL INF = 1e18;
int N, M;
bool BellmanFord()
{
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge.A;
            int v = edge.B;
            int w = edge.C;
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
        int u = edge.A;
        int v = edge.B;
        int w = edge.C;

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

    dist.resize(N + 1, INF);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    bool minuFlag = BellmanFord();

    if (minuFlag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == INF)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dist[i] << endl;
            }
        }
    }
}