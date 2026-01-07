#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<int> indgree;
vector<int> buildTime;
vector<int> totalTime;
vector<vector<int>> buildOrder;
queue<int> q;
int N;

void Input()
{
    cin >> N;

    indgree.resize(N + 1, 0);
    buildTime.resize(N + 1, 0);
    totalTime.resize(N + 1, 0);
    buildOrder.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> buildTime[i];

        while (true)
        {
            int preBuild;
            cin >> preBuild;

            if (preBuild == -1)
                break;

            buildOrder[preBuild].push_back(i);
            indgree[i]++;
        }
    }
}

void TopologicalSort()
{
    for (int i = 1; i <= N; i++)
    {
        if (indgree[i] == 0)
        {
            totalTime[i] = buildTime[i];
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : buildOrder[cur])
        {
            totalTime[next] = max(totalTime[next], totalTime[cur] + buildTime[next]);
            indgree[next]--;

            if (indgree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

void Output()
{
    for (int i = 1; i <= N; i++)
    {
        cout << totalTime[i] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    TopologicalSort();
    Output();
}