#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

using pii = pair<int, int>;
const int INF = numeric_limits<int>::max();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vector<priority_queue<int>> dist(n + 1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1].push(0);
    pq.push({0, 1});

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        for (const auto& edge : adj[current_node])
        {
            int neighbor_cost = edge.first;
            int neighbor_node = edge.second;
            int new_dist = current_cost + neighbor_cost;

            if (dist[neighbor_node].size() < k)
            {
                dist[neighbor_node].push(new_dist);
                pq.push({new_dist, neighbor_node});
            }

            else if (new_dist < dist[neighbor_node].top())
            {
                dist[neighbor_node].pop();
                dist[neighbor_node].push(new_dist);
                pq.push({new_dist, neighbor_node});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() < k)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dist[i].top() << '\n';    
        }
    }
}