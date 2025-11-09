#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    cin >> N;
    vector<int> num(N);

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    cin >> X;
    sort(num.begin(), num.end());

    int StartIdx = 0;
    int EndIdx = N - 1;
    int cnt = 0;
    while (StartIdx < EndIdx)
    {
        int sum = num[StartIdx] + num[EndIdx];

        if (sum == X)
        {
            cnt++;
            EndIdx--;
            StartIdx++;
        }
        else if (sum > X)
        {
            EndIdx--;
        }

        else
        {
            StartIdx++;
        }
    }

    cout << cnt << '\n';
}