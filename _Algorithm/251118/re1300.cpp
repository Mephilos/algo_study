#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, k;
    cin >> N >> k;

    int lo = 0;
    int hi = k;
    int answer = 0;
    while (lo <= hi)
    {
        int cnt = 0;
        int mid = (lo + hi) / 2;
        for (int i = 1; i <= N; i++)
        {
            cnt = min(N, mid / i);
        }

        if (cnt >= mid)
        {
            answer = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << answer << '\n';
}