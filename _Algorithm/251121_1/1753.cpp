#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
const int INF = 1e9;
int V, E, K;

vector<vector<pair<int, int>>> node;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int start)
{
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;

        pq.pop();

        if (curCost > dist[curNode])
        {
            continue;
        }
        for (auto &edge : node[curNode])
        {
            int nei = edge.first;
            int wei = edge.second;

            int newCost = wei + curCost;
            if (newCost < dist[nei])
            {
                dist[nei] = newCost;
                pq.push({newCost, nei});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;
    node.resize(V + 1);
    dist.resize(V + 1, INF);
    for (int i = 1; i <= V; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[u].push_back({v, w});
    }
    dijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }
}