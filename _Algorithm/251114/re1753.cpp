#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <functional>

using namespace std;

vector<vector<pair<int, int>>> node;
vector<int> dist;

int V, E, K;
const int INF = INT_MAX;
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
            int neighbor = edge.first;
            int wight = edge.second;

            int newCost = wight + curCost;

            if (newCost < dist[neighbor])
            {
                dist[neighbor] = newCost;
                pq.push({newCost, neighbor});
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
        int u, w, v;
        cin >> u >> w >> v;

        node[u].push_back({w, v});
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