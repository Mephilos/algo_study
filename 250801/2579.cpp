// 계단 오르기 실3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> score(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> score[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(3,0));

    dp[1][1] = score[1];
    dp[1][2] = 0;

    if (N > 1)
    {
        dp[2][1] = score[2];
        dp[2][2] = score[1] + score[2];
    }

    for (int i = 3; i <= N; i++)
    {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];

        dp[i][2] = dp[i - 1][1] + score[i];
    }

    cout << max(dp[N][1], dp[N][2]) << '\n';
}