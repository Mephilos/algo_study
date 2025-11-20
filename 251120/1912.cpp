#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> num(N + 1);
    s for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }

    vector<int> dp(N + 1, 0);

    dp[1] = num[1];

    int answer = dp[1];

    for (int i = 1; i <= N; i++)
    {
        dp[i] = max(num[i], dp[i - 1] + num[i]);

        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';
}