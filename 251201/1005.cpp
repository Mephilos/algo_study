#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<vector<int>> buildOrder;
vector<int> indgree;
vector<int> totalTime;
vector<int> buildTime;
queue<int> q;

int T, N, K, W;

void Input()
{
    cin >> N >> K;

    totalTime.clear();
    buildTime.clear();
    indgree.clear();
    buildOrder.clear();

    totalTime.resize(N + 1, 0);
    buildTime.resize(N + 1);
    indgree.resize(N + 1, 0);
    buildOrder.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> buildTime[i];
    }
    for (int i = 0; i < K; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        buildOrder[num1].push_back(num2);
        indgree[num2]++;
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
    cin >> W;
    cout << totalTime[W] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T-- > 0)
    {
        Input();
        TopologicalSort();
        Output();
    }
}