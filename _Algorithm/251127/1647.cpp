#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;
#define endl '\n'

vector<int> parent;
vector<tuple<int, int, int>> edges;
int N, M;
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

    cin >> N >> M;
    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());

    int sum = 0;
    int edgeMax = 0;
    for (auto &edge : edges)
    {
        auto [w, u, v] = edge;

        if (uniSet(u, v))
        {
            sum += w;
            edgeMax = w;
        }
    }

    cout << sum - edgeMax << endl;
}