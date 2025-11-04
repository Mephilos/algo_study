#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &node, vector<bool> &isBisit, vector<int> &bisitNum, int R)
{
    int count = 1;
    queue<int> q;
    q.push(R);
    isBisit[R] = true;
    bisitNum[R] = count;
    count++;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i : node[temp])
        {
            if (!isBisit[i])
            {
                isBisit[i] = true;
                bisitNum[i] = count;
                count++;
                q.push(i);
            }
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
    vector<int> bisitNum(N + 1);

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

    BFS(node, isBisit, bisitNum, R);

    for (int i = 1; i <= N; i++)
    {
        cout << bisitNum[i] << '\n';
    }
}