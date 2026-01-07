#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> parent;
vector<int> ranx;

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }

    return parent[u] = find(parent[u]);
}
void uniSet(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (ranx[u] > ranx[v])
        swap(u, v);

    parent[u] = v;

    if (ranx[u] == ranx[v])
        ranx[v]++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n);
    ranx.resize(n, 0);

    iota(parent.begin(), parent.end(), 0);

    int cnt = 0;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (cnt != 0)
            continue;

        if (find(u) == find(v))
            cnt = i;

        else
            uniSet(u, v);
    }

    cout << cnt << '\n';
}