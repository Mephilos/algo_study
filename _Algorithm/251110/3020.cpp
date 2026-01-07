#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;

    cin >> n >> h;

    vector<int> _top(h + 1, 0);
    vector<int> _bottom(h + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
        {
            _top[temp]++;
        }
        else
        {
            _bottom[temp]++;
        }
    }

    for (int i = h - 1; i >= 1; i--)
    {
        _bottom[i] = _bottom[i] + _bottom[i + 1];
        _top[i] = _top[i] + _top[i + 1];
    }

    int minHit = n + 1;
    int minCnt = 0;

    for (int i = 1; i <= h; i++)
    {
        int _bottomHit = _bottom[i];
        int _topHit = _top[h - i + 1];

        int currentHit = _bottomHit + _topHit;

        if (currentHit < minHit)
        {
            minHit = currentHit;
            minCnt = 1;
        }
        else if (currentHit == minHit)
        {
            minCnt++;
        }
    }

    cout << minHit << ' ' << minCnt << '\n';
}