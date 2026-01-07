#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path;
vector<int> path2;
vector<bool> isVisit;
int N, M;

void Solve(int cnt)
{
    if (cnt == M)
    {
        for (auto i : path2)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isVisit[i])
        {
            isVisit[i] = true;
            path2.push_back(path[i]);

            Solve(cnt + 1);

            isVisit[i] = false;
            path2.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    path.clear();
    isVisit.clear();
    path.resize(N + 1);
    isVisit.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> path[i];
    }

    sort(path.begin(), path.end());

    Solve(0);
}