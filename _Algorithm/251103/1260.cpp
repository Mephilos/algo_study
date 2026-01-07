#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> bisit;

void DFS(int node)
{
    cout << node << ' ';
    bisit[node] = true;
    for (int n : graph[node])
    {
        if (!bisit[n])
        {
            DFS(n);
        }
    }
}
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    bisit[node] = true;

    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << ' ';
        q.pop();
        for (int i : graph[temp])
        {
            if (!bisit[i])
            {
                bisit[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, V;

    cin >> N >> M >> V;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }

    for (int i = 0; i < N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    bisit = vector<bool>(N + 1, false);
    DFS(V);
    cout << '\n';
    fill(bisit.begin(), bisit.end(), false);
    BFS(V);
    cout << '\n';
}