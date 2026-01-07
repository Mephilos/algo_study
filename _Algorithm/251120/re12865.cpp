#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> item(n);

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].first >> item[i].second;
    }

    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int w = item[i].first;
        int v = item[i].second;

        for (int j = k; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[k] << '\n';
}