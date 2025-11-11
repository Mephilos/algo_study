#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> path;

void Solve(int cnt)
{
    if (cnt == M)
    {
        for (int i : path)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        path.push_back(i);

        Solve(cnt + 1);

        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    Solve(0);
}