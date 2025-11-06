#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tri(n + 1);
    vector<vector<int>> dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        tri[i].resize(i + 1);
        dp[i].resize(i + 1);
        for (int j = 1; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    dp[1][1] = tri[1][1];

    // dp[2][1] = dp[1][1] + tri[2][1];
    // dp[2][2] = dp[1][1] + tri[2][2];

    // dp[3][1] = dp[2][1] + tri[3][1];
    // dp[3][2] = max(dp[2][1], dp[2][2]) + tri[3][2];
    // dp[3][3] = dp[2][2] + tri[3][3];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + tri[i][j];
            }

            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
            }
        }
    }

    int dpMax = 0;
    for (int i = 1; i <= n; i++)
    {
        dpMax = max(dpMax, dp[n][i]);
    }

    cout << dpMax << '\n';
}