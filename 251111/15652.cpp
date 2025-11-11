#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> path;

void Solve(int cnt, int start)
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

    for (int i = start; i <= N; i++)
    {
        path.push_back(i);

        Solve(cnt + 1, i);

        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    Solve(0, 1);
}