#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>> &comp, vector<bool> &isBisit, int j, int &count)
{
    if (isBisit[j])
        return;
    count++;
    isBisit[j] = true;
    for (int i : comp[j])
    {
        if (!isBisit[i])
        {
            DFS(comp, isBisit, i, count);
        }
    }
}

void BFS(vector<vector<int>> &comp, vector<bool> &isBisit, int start, int &count)
{
    queue<int> q;
    q.push(start);
    isBisit[start] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i : comp[temp])
        {
            if (!isBisit[i])
            {
                q.push(i);
                isBisit[i] = true;
                count++;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int start = 1;
    int count = 0;
    cin >> N;
    vector<vector<int>> comp(N + 1);
    vector<bool> isBisit(N + 1);

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int m, n;
        cin >> n >> m;
        comp[n].push_back(m);
        comp[m].push_back(n);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(comp[i].begin(), comp[i].end());
    }
    // BFS(comp, isBisit, start, count);
    DFS(comp, isBisit, start, count);

    cout << count - 1 << '\n';
}