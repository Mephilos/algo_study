#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

vector<int> parent;
struct Star
{
    double x, y;
};
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

    if (v == u)
        return false;

    parent[u] = v;
    return true;
}

double dist(Star &a, Star &b)
{
    double px = a.x - b.x;
    double py = a.y - b.y;

    return sqrt(pow(px, 2) + pow(py, 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    parent.resize(N);

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    vector<Star> stars(N);

    for (int i = 0; i < N; i++)
    {
        cin >> stars[i].x >> stars[i].y;
    }

    vector<tuple<double, int, int>> star;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double distValue = dist(stars[i], stars[j]);
            star.push_back({distValue, i, j});
        }
    }

    sort(star.begin(), star.end());

    int cnt = 0;
    double totalCost = 0;
    for (auto &e : star)
    {
        auto [w, u, v] = e;

        if (uniSet(u, v))
        {
            totalCost += w;
            cnt++;
            if (cnt >= N - 1)
            {
                break;
            }
        }
    }
    cout << fixed << setprecision(2) << totalCost << '\n';
}