#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int dp[11];

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

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        result.push_back(dp[n]);
    }

    for (int r : result)
    {
        cout << r << '\n';
    }
}