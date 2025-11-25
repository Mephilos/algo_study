#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;

void dfs(vector<vector<int>> &node, vector<bool> &isVisited, int V)
{
    isVisited[V] = true;
    cout << V << ' ';

    for (auto i : node[V])
    {
        if (!isVisited[i])
        {
            dfs(node, isVisited, i);
        }
    }
}

void bfs(vector<vector<int>> &node, vector<bool> isVisited, int v)
{
    queue<int> q;
    q.push(V);
    isVisited[V] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << ' ';
        for (auto i : node[temp])
        {
            if (!isVisited[i])
            {
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;

    vector<vector<int>> node(N + 1);
    vector<bool> isVisited(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int u, v;

        cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 0; i <= N; i++)
    {
        sort(node[i].begin(), node[i].end());
    }

    dfs(node, isVisited, V);
    cout << '\n';
    fill(isVisited.begin(), isVisited.end(), false);

    bfs(node, isVisited, V);
    cout << '\n';
}