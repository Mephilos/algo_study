#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<vector<int>> member;
vector<bool> flag;
int N;
int answer = INT_MAX;
void solve(int cnt, int stIdx)
{
    if (N / 2 == cnt)
    {
        int start = 0;
        int link = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (flag[i] && flag[j])
                {
                    start += (member[i][j] + member[j][i]);
                }
                else if (!flag[i] && !flag[j])
                {
                    link += (member[i][j] + member[j][i]);
                }
            }
        }
        answer = min(answer, abs(start - link));

        return;
    }

    for (int i = stIdx; i < N; i++)
    {
        if (!flag[i])
        {
            flag[i] = true;
            solve(cnt + 1, i + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    member.resize(N, vector<int>(N));
    flag.resize(N);
    for (auto &i : member)
    {
        for (int &j : i)
        {
            cin >> j;
        }
    }
    solve(0, 0);

    cout << answer << '\n';
}