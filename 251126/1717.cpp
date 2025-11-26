#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> ranx;
int n, m;
int find(int u)
{
    if (parent[u] == u)
        return u;
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

    cin >> n >> m;
    parent.resize(n + 1);
    ranx.resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            uniSet(a, b);
        }
        else if (op == 1)
        {
            if (find(a) == find(b))
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}