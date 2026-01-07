#include <iostream>
#include <vector>

using namespace std;

const int INF = 1667;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);

    dp[0] = 0;
    for (int i = 3; i <= n; i++)
    {
        if (i >= 3 && dp[i - 3] != INF)
        {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }

        if (i >= 5 && dp[i - 5] != INF)
        {
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }

    if (dp[n] == INF)
    {
        cout << -1 << '\n';
    }
    else
        cout << dp[n] << '\n';
}