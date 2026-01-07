#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> root;
int n, m;
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
    {
        return;
    }

    if (root[u] > root[v])
        swap(u, v);
    parent[u] = v;

    if (root[u] == root[v])
        root[v]++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    parent.resize(n + 1);
    root.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
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
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}