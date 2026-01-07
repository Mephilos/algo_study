#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> node;
static vector<bool> bisit;
static vector<int> bisitCnt;

void DFS(int R, int D)
{
    bisit[R] = true;
    bisitCnt[R] = D;

    for (int i : node[R])
    {
        if (!bisit[i])
        {
            DFS(i, D + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, R;
    cin >> N >> M >> R;
    node.resize(N + 1);
    bisit.resize(N + 1);
    bisitCnt.resize(N + 1, -1);
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
    DFS(R, 0);

    for (int i = 1; i <= N; i++)
    {
        cout << bisitCnt[i] << '\n';
    }
}