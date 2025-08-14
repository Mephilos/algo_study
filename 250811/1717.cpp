#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parent;

int find_set(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find_set(parent[x]);
}

void unite_sets(int x, int y)
{
    int rootX = find_set(x);
    int rootY = find_set(y);

    if (rootX != rootY)
    {
        if (rootX < rootY)
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootX] = rootY;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0)
        {
            unite_sets(a, b);
        }
        else
        {
            if (find_set(a) == find_set(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}