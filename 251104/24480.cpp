#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

static vector<int> bisitNum;
static int bisitCounter = 1;

bool Compare(int a, int b)
{
    return a > b;
}

void DFS(vector<vector<int>> &node, vector<bool> &isBisit, int R)
{
    if (isBisit[R])
        return;
    isBisit[R] = true;
    bisitNum[R] = bisitCounter;
    bisitCounter++;
    for (int i : node[R])
    {
        if (!isBisit[i])
        {
            DFS(node, isBisit, i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> node(N + 1);
    vector<bool> isBisit(N + 1);
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
        sort(node[i].begin(), node[i].end(), greater<int>());
    }

    DFS(node, isBisit, R);

    for (int i = 1; i <= N; i++)
    {
        cout << bisitNum[i] << '\n';
    }
}