#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;
vector<int> input;

void solve(int cnt, int start)
{
    if (cnt == M)
    {
        for (int i : num)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++)
    {
        num.push_back(input[i]);

        solve(cnt + 1, i);

        num.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    input.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    auto it = unique(input.begin(), input.end());

    input.erase(it, input.end());

    N = input.size();

    solve(0, 0);
}