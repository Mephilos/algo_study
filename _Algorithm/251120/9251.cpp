#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int strlen1 = str1.length();
    int strlen2 = str2.length();

    vector<vector<int>> dp(strlen1 + 1, vector<int>(strlen2 + 1));

    for (int i = 1; i <= strlen1; i++)
    {
        for (int j = 1; j <= strlen2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[strlen1][strlen2] << '\n';
}