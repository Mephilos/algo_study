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
    vector<ll> lanLine(K);

    ll _max = 0;
    ll _min = 1;

    for (int i = 0; i < K; i++)
    {
        cin >> lanLine[i];
        if (_max < lanLine[i])
            _max = lanLine[i];
    }

    ll answer = 0;
    while (_min <= _max)
    {
        ll mid = (_max + _min) / 2;
        ll cnt = 0;

        for (int i = 0; i < K; i++)
        {
            cnt += (lanLine[i] / mid);
        }

        if (cnt >= N)
        {
            answer = mid;

            _min = mid + 1;
        }
        else
        {
            _max = mid - 1;
        }
    }
    cout << answer << '\n';
}
