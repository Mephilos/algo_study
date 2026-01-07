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

    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    vector<int> dp(N + 1, 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int cnt = *max_element(dp.begin(), dp.end());

    cout << cnt << '\n';

    vector<int> output;

    for (int i = N; i >= 1; i--)
    {
        if (cnt == dp[i])
        {
            output.push_back(A[i]);
            cnt--;
        }
    }

    reverse(output.begin(), output.end());

    for (int i : output)
    {
        cout << i << ' ';
    }
    cout << '\n';
}