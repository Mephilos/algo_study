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
    {
        return u;
    }
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

    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    vector<tuple<int, int, int>> lines;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        lines.push_back({c, a, b});
    }

    sort(lines.begin(), lines.end());

    int totalCost = 0;
    int cnt = 0;

    for (auto &line : lines)
    {
        auto [c, a, b] = line;

        if (uniSet(a, b))
        {
            totalCost += c;
            cnt++;
            if (cnt >= N - 1)
                break;
        }
    }

    cout << totalCost << '\n';
}