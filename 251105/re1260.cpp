#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> node;
vector<bool> bisit;

void DFS(int V)
{
    cout << V << '\n';
    bisit[V] = true;
    for (int i : node[V])
    {
        if (!bisit[i])
        {
            DFS(i);
        }
    }
}
void BFS(int V)
{
    queue<int> q;
    q.push(V);
    bisit[V] = true;
    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << '\n';
        q.pop();
        for (int i : node[temp])
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

    node.resize(N + 1);
    bisit.resize(N + 1);

    for (int i = 1; i <= M; i++)
    {
        int n, m;
        cin >> n >> m;

        node[n].push_back(m);
        node[m].push_back(n);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(node[i].begin(), node[i].end());
    }

    DFS(V);

    fill(bisit.begin(), bisit.end(), false);

    BFS(V);
}