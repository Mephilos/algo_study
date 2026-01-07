#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    vector<vector<int>> dp(N + 1, vector<int>(K + 1));

    vector<int> w(N + 1);
    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= w[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][K] << '\n';
}