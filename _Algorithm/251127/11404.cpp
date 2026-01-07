#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define endl '\n';

vector<int> dist;
vector<vector<pair<int, int>>> node;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

const int INF = 1e9;
int n, m;

void Dijkstra(int start)
{
    fill(dist.begin(), dist.end(), INF);
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

    cin >> n >> m;
    node.resize(n + 1);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++)
    {
        Dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] == INF)
            {
                cout << "0" << ' ';
            }
            else
            {
                cout << dist[j] << ' ';
            }
        }
        cout << endl;
    }
}