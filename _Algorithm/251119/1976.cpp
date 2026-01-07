#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> path;
vector<int> ranx;

int find(int u)
{
    if (path[u] == u)
        return u;

    return path[u] = find(path[u]);
}

void uniSet(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (ranx[u] > ranx[v])
        swap(u, v);
    path[u] = v;

    if (ranx[u] == ranx[v])
        ranx[v]++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    path.resize(N + 1);
    ranx.resize(N + 1, 0);

    iota(path.begin(), path.end(), 0);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 1 && j > i)
            {
                uniSet(i, j);
            }
        }
    }

    vector<int> plan(M);

    for (int i = 0; i < M; i++)
    {
        cin >> plan[i];
    }

    bool flag = false;
    int start = find(plan[0]);
    for (int i = 1; i < M; i++)
    {
        if (start != find(plan[i]))
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}