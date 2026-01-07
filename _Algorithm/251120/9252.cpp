#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[len1][len2] << '\n';

    if (dp[len1][len2] != 0)
    {
        string answer;

        while (len1 > 0 && len2 > 0)
        {
            if (s1[len1 - 1] == s2[len2 - 1])
            {
                answer.push_back(s1[len1 - 1]);
                len1--;
                len2--;
            }
            else
            {
                if (dp[len1][len2] == dp[len1 - 1][len2])
                {
                    len1--;
                }
                else
                {
                    len2--;
                }
            }
        }

        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }
}