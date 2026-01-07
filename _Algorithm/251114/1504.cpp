#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX - 1;

int N, E;

vector<vector<pair<int, int>>> node;
vector<int> lowCost;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    lowCost[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;

        pq.pop();

        if (curCost > lowCost[curNode])
        {
            continue;
        }

        for (auto &edge : node[curNode])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            int newCost = weight + curCost;

            if (newCost < lowCost[neighbor])
            {
                lowCost[neighbor] = newCost;
                pq.push({newCost, neighbor});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;

    node.resize(N + 1);
    lowCost.resize(N + 1, INF);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    dijkstra(1);
    int lak1 = lowCost[v1];
    int lak12 = lowCost[v2];

    fill(lowCost.begin(), lowCost.end(), INF);
    dijkstra(v1);
    int lak22 = lowCost[v2];
    int lak2 = lowCost[N];
    fill(lowCost.begin(), lowCost.end(), INF);
    dijkstra(v2);
    int lak3 = lowCost[N];
    int lak32 = lowCost[v1];

    long long path1 = -1;
    long long path2 = -1;
    if (lak1 != INF && lak22 != INF && lak3 != INF)
    {
        path1 = (long long)lak1 + lak22 + lak3;
    }
    if (lak12 != INF && lak2 != INF && lak32 != INF)
    {
        path2 = (long long)lak12 + lak2 + lak32;
    }

    int answer = -1;

    if (path1 != -1 && path2 != -1)
    {
        answer = min(path1, path2);
    }
    else if (path1 != -1)
    {
        answer = path1;
    }
    else if (path2 != -1)
    {
        answer = path2;
    }

    cout << answer << '\n';
}