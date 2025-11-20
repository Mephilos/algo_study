#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while (T-- > 0)
    {
        int n;
        cin >> n;

        vector<long long> dp(n + 1);

        dp[1] = 1;
        if (n >= 2)
            dp[2] = 2;
        if (n >= 3)
            dp[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
        }

        cout << dp[n] % 1000000009 << '\n';
    }
}

// long long dp[1000001];

// void preDp()
// {
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 4;

//     for (int i = 4; i <= 1000000; i++)
//     {
//         dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     preDp();

//     int T;

//     cin >> T;

//     while (T-- > 0)
//     {
//         int n;
//         cin >> n;

//         cout << dp[n] % 1000000009 << '\n';
//     }
// }