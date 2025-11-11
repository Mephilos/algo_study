#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> lesson(N);
    for (int &i : lesson)
    {
        cin >> i;
    }

    int lo = *max_element(lesson.begin(), lesson.end());
    int hi = accumulate(lesson.begin(), lesson.end(), 0);
    int answer = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = 1;
        int diskLength = 0;
        for (int i = 0; i < N; i++)
        {
            if (diskLength + lesson[i] > mid)
            {
                cnt++;
                diskLength = lesson[i];
            }
            else
            {
                diskLength += lesson[i];
            }
        }
        if (cnt > M)
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