#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <utility>
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

double dist(const pair<double, double> &a, const pair<double, double> &b)
{
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    parent.resize(N);
    iota(parent.begin(), parent.end(), 0);

    vector<pair<double, double>> stars(N);

    for (int i = 0; i < N; i++)
    {
        cin >> stars[i].first >> stars[i].second;
    }

    vector<tuple<double, int, int>> star;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double distValue = dist(stars[i], stars[j]);
            star.push_back({distValue, i, j});
        }
    }

    sort(star.begin(), star.end());
    int cnt = 0;
    double totalValue = 0;
    for (const auto &edge : star)
    {
        auto [w, u, v] = edge;

        if (uniSet(u, v))
        {
            totalValue += w;
            cnt++;
            if (N - 1 <= cnt)
                break;
        }
    }

    cout << fixed << setprecision(2) << totalValue << '\n';
}