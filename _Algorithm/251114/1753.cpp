#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <functional>

using namespace std;

vector<vector<pair<int, int>>> node;
vector<int> dist;
int INF = INT_MAX;

int V, E, K;
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currentCost = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        if (currentCost > dist[currentNode])
        {
            continue;
        }

        for (auto &edge : node[currentNode])
        {
            int neib = edge.first;
            int wight = edge.second;

            int newCost = currentCost + wight;

            if (newCost < dist[neib])
            {
                dist[neib] = newCost;
                pq.push({newCost, neib});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;
    node.resize(V + 1, vector<pair<int, int>>(V + 1));
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