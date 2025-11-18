#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N, M;
const int INF = 1e9;
vector<vector<pair<int, int>>> node;
vector<int> cost;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        if (curCost > cost[curNode])
        {
            continue;
        }
        for (auto &edge : node[curNode])
        {
            int neib = edge.first;
            int wei = edge.second;

            int newCost = wei + curCost;

            if (newCost < cost[neib])
            {
                cost[neib] = newCost;
                pq.push({newCost, neib});
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
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back({b, c});
    }

    int s, e;

    cin >> s >> e;

    dijkstra(s);

    cout << cost[e] << '\n';
}