#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, K;

    cin >> N >> K;

    ll low = 1;
    ll high = K;
    ll result = 0;
    while (low <= high)
    {
        ll cnt = 0;
        ll mid = (low + high) / 2;

        for (int i = 1; i <= N; i++)
        {
            cnt += min(N, mid / i);
        }

        if (cnt < K)
        {

            low = mid + 1;
        }
        else
        {
            result = mid;
            high = mid - 1;
        }
    }
    cout << result << '\n';
}
