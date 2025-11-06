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
    vector<int> wine(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    if (n >= 2)
        dp[2] = wine[1] + wine[2];
    if (n >= 3)
        dp[3] = max({wine[1] + wine[2], wine[1] + wine[3], wine[2] + wine[3]});

    for (int i = 4; i <= n; i++)
    {
        int c = dp[i - 1];
        int c1 = dp[i - 2] + wine[i];
        int c2 = dp[i - 3] + wine[i - 1] + wine[i];
        dp[i] = max({c, c1, c2});
    }

    cout << dp[n] << '\n';
}