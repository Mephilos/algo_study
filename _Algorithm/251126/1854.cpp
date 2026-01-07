#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

priority_queue<PII, vector<PII>, greater<PII>> pq;
vector<vector<pair<int, int>>> edges;
vector<priority_queue<int>> dist;
const int INF = 1e9;
int n, m, k;

void Dijkstra(int start)
{
    dist[start].push(0);
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;

        pq.pop();

        for (auto &edge : edges[curNode])
        {
            int nei = edge.first;
            int wei = edge.second;
            int newCost = curCost + wei;

            if (dist[nei].size() < k)
            {
                dist[nei].push(newCost);
                pq.push({newCost, nei});
            }

            else if (newCost < dist[nei].top())
            {
                dist[nei].pop();
                dist[nei].push(newCost);
                pq.push({newCost, nei});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    edges.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
    }

    Dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() < k)
        {
            cout << -1 << '\n';
        }
        else
            cout << dist[i].top() << '\n';
    }
}