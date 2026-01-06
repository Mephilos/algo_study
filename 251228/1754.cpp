#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

const int INF = 1e9;
vector<vector<pair<int, int>>> edges;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Daijkstra(int start)
{
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curCost)
        {
            continue;
        }

        for (auto edge : edges[curNode])
        {
            int nei = edge.first;
            int wei = edge.second;

            int newCost = wei + curCost;
            if (dist[nei] > newCost)
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

    int V, E, K;
    cin >> V >> E >> K;

    edges.resize(V + 1);
    dist.resize(V + 1, INF);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    Daijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }

        else
            cout << dist[i] << endl;
    }
}