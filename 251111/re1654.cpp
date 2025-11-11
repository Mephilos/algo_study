#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N;

    cin >> K >> N;
    vector<int> lanLine(K);
    for (int i = 0; i < K; i++)
    {
        cin >> lanLine[i];
    }

    ll low = 1;
    ll high = *max_element(lanLine.begin(), lanLine.end());
    ll result = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        int cnt = 0;

        for (int i = 0; i < K; i++)
        {
            cnt += lanLine[i] / mid;
        }

        if (cnt >= N)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << result << '\n';
}
