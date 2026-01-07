#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'

int N;
int indgree[501];
int buildTime[501];
int totalTime[501];
vector<int> buildMap[501];
queue<int> q;

void Input()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> buildTime[i];

        while (true)
        {
            int preBuild;
            cin >> preBuild;

            if (preBuild == -1)
                break;

            buildMap[preBuild].push_back(i);
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
            q.push(i);
            totalTime[i] = buildTime[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : buildMap[cur])
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