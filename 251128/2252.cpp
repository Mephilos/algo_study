#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'

vector<int> indgree;
vector<vector<int>> height;
queue<int> q;
int N, M;

void TopologicalSort()
{
    for (int i = 1; i <= N; i++)
    {
        if (indgree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : height[cur])
        {
            indgree[next]--;

            if (indgree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    height.resize(N + 1);
    indgree.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        height[a].push_back(b);
        indgree[b]++;
    }

    TopologicalSort();
    cout << '\n';
}