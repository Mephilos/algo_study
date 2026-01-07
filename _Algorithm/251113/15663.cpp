#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;
vector<int> path;
vector<bool> flag;

void solve(int n)
{
    if (n == M)
    {
        for (auto i : path)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    int pickNum = 0;

    for (int i = 0; i < N; i++)
    {
        if (!flag[i] && pickNum != num[i])
        {
            path.push_back(num[i]);
            flag[i] = true;
            pickNum = num[i];

            solve(n + 1);
            flag[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    num.resize(N);
    flag.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    solve(0);
}