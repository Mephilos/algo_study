#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bisitCount = 1;
vector<int> bisitNum;

void DFS(vector<vector<int>> &graph, vector<bool> &bisit, int R)
{
    if (bisit[R])
        return;
    bisit[R] = true;
    bisitNum[R] = bisitCount;
    bisitCount++;
    for (auto i : graph[R])
    {
        if (!bisit[i])
        {
            DFS(graph, bisit, i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    vector<bool> bisit(N + 1);
    bisitNum.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;

        graph[n].push_back(m);
        graph[m].push_back(n);
    }

    for (int i = 0; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, bisit, R);

    for (int i = 1; i <= N; i++)
    {
        cout << bisitNum[i] << '\n';
    }

    // for (auto v : bisitNum)
    // {
    //     cout << v << '\n';
    // }
}