#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define endl '\n'

int N, M;
vector<int> adj[32001];
int indgree[32001];

void TopologicalSort()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        if (indgree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << endl;

        for (auto next : adj[cur])
        {
            indgree[next]--;

            if (indgree[next] == 0)
            {
                pq.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indgree[b]++;
    }

    TopologicalSort();
    cout << endl;
}