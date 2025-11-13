#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
vector<int> path;

int N, M;

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
        path.push_back(input[i]);
        cout << "+++" << i << "+++" << '\n';
        Solve(cnt + 1, i);

        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    input.clear();
    input.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    Solve(0, 1);
}