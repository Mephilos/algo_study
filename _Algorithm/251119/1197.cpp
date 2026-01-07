#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> parent;

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

bool uniSet(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    parent[u] = v;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    parent.resize(V + 1);

    iota(parent.begin(), parent.end(), 0);

    int cnt = 0;
    long long totalCost = 0;

    for (auto &edge : edges)
    {
        auto [w, u, v] = edge;

        if (uniSet(u, v))
        {
            totalCost += w;
            cnt++;
            if (cnt >= V - 1)
                break;
        }
    }
    cout << totalCost << '\n';
}