#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

const int INF = INT_MAX;
int N, M;

vector<vector<pair<int, int>>> node;
vector<int> cost;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > cost[curNode])
        {
            continue;
        }

        for (auto &edge : node[curNode])
        {
            int neigbhor = edge.first;
            int wight = edge.second;

            int newCost = wight + curCost;

            if (newCost < cost[neigbhor])
            {
                cost[neigbhor] = newCost;
                pq.push({newCost, neigbhor});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    node.resize(N + 1);
    cost.resize(N + 1, INF);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[u].push_back({v, w});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start);

    cout << cost[end] << '\n';
}