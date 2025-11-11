#include <iostream>
#include <vector>

using namespace std;

void Solve(int cnt, vector<int> &path, vector<bool> &isVisited, int N, int M)
{
    if (cnt == M)
    {
        for (auto i : path)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            path.push_back(i);

            Solve(cnt + 1, path, isVisited, N, M);

            isVisited[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> path;
    vector<bool> isVisited(N + 1);

    Solve(0, path, isVisited, N, M);
}