#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == INF)
    {
        cout << -1 << '\n';
    }
    else
        cout << dp[k] << '\n';
}