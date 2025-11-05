#include <iostream>
#include <vector>

using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp(11);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int T;
    cin >> T;

    vector<int> result;
    while (T-- > 0)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}