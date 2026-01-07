#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, X;
const int INF = 1e9;

vector<vector<pair<int, int>>> node;
vector<vector<pair<int, int>>> reverseNode;

vector<int> dist;
vector<int> reverseDist;

void dijkstra(int start, vector<int> &dist, vector<vector<pair<int, int>>> &node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist.begin(), dist.end(), INF);

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

        for (auto &i : node[curNode])
        {
            int nei = i.first;
            int cost = i.second;

            int newCost = cost + curCost;

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

    cin >> N >> M >> X;

    node.resize(N + 1);
    dist.resize(N + 1);
    reverseNode.resize(N + 1);
    reverseDist.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e, t;

        cin >> s >> e >> t;

        node[s].push_back({e, t});
        reverseNode[e].push_back({s, t});
    }

    dijkstra(X, dist, node);
    dijkstra(X, reverseDist, reverseNode);
    int _max = 0;

    for (int i = 1; i <= N; i++)
    {
        int total = dist[i] + reverseDist[i];
        _max = max(_max, total);
    }
    cout << _max << '\n';
}