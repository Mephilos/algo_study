#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<int> parent;
vector<tuple<int, int, int>> edges;
int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}
bool uniset(int u, int v)
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
    parent.resize(V + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());

    int totalCost = 0;
    for (auto &edge : edges)
    {
        auto [c, a, b] = edge;

        if (uniset(a, b))
        {
            totalCost += c;
        }
    }
    cout << totalCost << endl;
}