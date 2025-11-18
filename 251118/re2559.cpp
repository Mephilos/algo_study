#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> num(N);

    for (int &i : num)
    {
        cin >> i;
    }

    int sum = 0;

    for (int i = 0; i < K; i++)
    {
        sum += num[i];
    }

    int max = sum;

    for (int i = 0; i < N - K; i++)
    {
        sum -= num[i];
        sum += num[K + i];
        if (max < sum)
        {
            max = sum;
        }
    }

    cout << max << '\n';
}