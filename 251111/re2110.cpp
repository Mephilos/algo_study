#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> dist(N);

    for (int i = 0; i < N; i++)
    {
        cin >> dist[i];
    }
    sort(dist.begin(), dist.end());

    int lo = 1;
    int hi = dist[N - 1] - dist[0];
    int result = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = 1;
        int lastPos = dist[0];

        for (int i = 1; i < N; i++)
        {
            if (dist[i] - lastPos >= mid)
            {
                cnt++;
                lastPos = dist[i];
            }
        }

        if (cnt >= C)
        {
            result = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << result << '\n';
}