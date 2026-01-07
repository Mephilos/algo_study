#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

int N, C;
vector<int> house;

int BinarySearch()
{
    int lo = 1;
    int hi = house[N - 1] - house[0];
    int answer = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = 1;
        int lastPos = house[0];

        for (int i = 1; i < N; i++)
        {
            if (house[i] - lastPos >= mid)
            {
                cnt++;
                lastPos = house[i];
            }
        }

        if (C <= cnt)
        {
            answer = mid;
            lo = mid + 1;
        }
        else if (C > cnt)
        {
            hi = mid - 1;
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    house.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    cout << BinarySearch() << endl;
}