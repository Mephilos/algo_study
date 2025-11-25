#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void uniset(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
        parent[u] = v;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        uniset(u, v);
    }
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}