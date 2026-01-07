#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, H;
    cin >> N >> H;

    vector<int> _top(H + 1);
    vector<int> _bottom(H + 1);

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
        {
            _bottom[temp]++;
        }
        else
        {
            _top[temp]++;
        }
    }

    for (int i = H - 1; i >= 1; i--)
    {
        _bottom[i] = _bottom[i + 1] + _bottom[i];
        _top[i] = _top[i + 1] + _top[i];
    }

    int minCnt = N + 1;
    int gugan = 0;

    for (int i = 1; i <= H; i++)
    {
        int _bHit = _bottom[i];
        int _tHit = _top[H - i + 1];
        int totalHit = _bHit + _tHit;

        if (minCnt > totalHit)
        {
            minCnt = totalHit;
            gugan = 1;
        }
        else if (minCnt == totalHit)
        {
            gugan++;
        }
    }
    cout << minCnt << ' ' << gugan << '\n';
}