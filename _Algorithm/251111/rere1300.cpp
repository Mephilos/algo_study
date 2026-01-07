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

    ll answer = 0;
    ll lo = 1;
    ll hi = K;
    while (lo <= hi)
    {
        ll cnt = 0;
        ll mid = (lo + hi) / 2;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(N, mid / i);
        }

        if (cnt < K)
        {
            lo = mid + 1;
        }
        else
        {
            answer = mid;
            hi = mid - 1;
        }
    }
    cout << answer << '\n';
}