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
    vector<vector<int>> house(n + 1, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
    {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = house[i][1] + min(dp[i - 1][2], dp[i - 1][0]);
        dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int last = std::min({dp[n][0], dp[n][1], dp[n][2]});

    cout << last << '\n';
}
