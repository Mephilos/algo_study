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

    vector<int> score(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }

    vector<int> dp(n + 1);

    dp[1] = score[1];
    if (n >= 2)
        dp[2] = score[2] + score[1];
    if (n >= 3)
        dp[3] = max(score[1] + score[3], score[2] + score[3]);

    for (int i = 4; i <= n; i++)
    {
        int c1 = dp[i - 2] + score[i];
        int c2 = dp[i - 3] + score[i - 1] + score[i];

        dp[i] = max(c1, c2);
    }

    cout << dp[n] << '\n';
}