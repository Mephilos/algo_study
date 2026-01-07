#include <iostream>
#include <vector>

using namespace std;

const int INF = 2001;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= N; i++)
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

    if (dp[N] != INF)
        cout << dp[N] << '\n';
    else
        cout << -1 << '\n';
}