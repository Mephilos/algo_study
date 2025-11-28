#include <iostream>
#include <vector>

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
        int check = q.front();
        q.pop();
        cout << check << ' ';

        for (int hei : height[check])
        {
            indgree[hei]--;
            if (indgree[hei] == 0)
            {
                q.push(hei);
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
    cout << endl;
}