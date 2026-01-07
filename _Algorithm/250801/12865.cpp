// 평범한 배낭 골5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    vector<int> W(N + 1);
    vector<int> V(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= W[i])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - W[i]] + V[i]);
            }
        }
    }
    cout << dp[N][K] << '\n';
}