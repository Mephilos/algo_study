#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
static vector<int> bisitNum;
static int bisitCount = 1;
void DFS(vector<vector<int>> &node, vector<bool> &bisit, int R)
{
    bisit[R] = true;
    bisitNum[R] = bisitCount;
    bisitCount++;
    for (int i : node[R])
    {
        if (!bisit[i])
            DFS(node, bisit, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> node(N + 1);
    vector<bool> bisit(N + 1);
    bisitNum.resize(N + 1);
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

    DFS(node, bisit, R);

    for (int i = 1; i <= N; i++)
    {
        cout << bisitNum[i] << '\n';
    }
}