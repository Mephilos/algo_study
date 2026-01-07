#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> node;
vector<int> dist;

int V, E, K;
const int INF = 1e9;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    dist[start] = 0;

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
            int nib = edge.first;
            int wig = edge.second;

            int newCost = wig + curCost;

            if (newCost < dist[nib])
            {
                dist[nib] = newCost;
                pq.push({newCost, nib});
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

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}