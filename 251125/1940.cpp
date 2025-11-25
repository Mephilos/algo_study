#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> num(N);

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    int startIdx = 0;
    int endIdx = N - 1;
    int cnt = 0;

    while (startIdx < endIdx)
    {
        int sum = num[startIdx] + num[endIdx];

        if (sum == M)
        {
            cnt++;
            startIdx++;
            endIdx--;
        }
        else if (sum > M)
        {
            endIdx--;
        }
        else
        {
            startIdx++;
        }
    }

    cout << cnt << '\n';
}