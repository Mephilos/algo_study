#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using LL = long long;
LL TEMP = 1000000000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<LL>> dp(n + 1, vector<LL>(10));

    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;

    if (n >= 2)
    {
        dp[2][0] = 1;
        dp[2][1] = 1;
        dp[2][2] = 2;
        dp[2][3] = 2;
        dp[2][4] = 2;
        dp[2][5] = 2;
        dp[2][6] = 2;
        dp[2][7] = 2;
        dp[2][8] = 2;
        dp[2][9] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % TEMP;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % TEMP;
            }
            else
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1] % TEMP;
        }
    }

    LL sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum = (sum + dp[n][i]) % TEMP;
    }

    cout << sum << '\n';
}