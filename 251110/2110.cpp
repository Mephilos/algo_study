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
    int high = dist[N - 1] - dist[0];
    int low = 1;

    int answer = 0;

    while (high >= low)
    {
        int cnt = 1;
        int lastDist = dist[0];
        int mid = (high + low) / 2;

        for (int i = 1; i < N; i++)
        {
            if (dist[i] - lastDist >= mid)
            {
                cnt++;
                lastDist = dist[i];
            }
        }
        if (cnt >= C)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
}