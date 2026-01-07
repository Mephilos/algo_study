#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int currentSum = 0;
    int tempMax = 0;
    int N, K;

    cin >> N >> K;
    vector<int> day(N);

    for (int i = 0; i < N; i++)
    {
        cin >> day[i];
    }

    for (int i = 0; i < K; i++)
    {
        currentSum += day[i];
    }

    tempMax = currentSum;

    for (int i = 1; i <= N - K; i++)
    {
        currentSum = currentSum - day[i - 1] + day[i + K - 1];
        if (tempMax < currentSum)
        {
            tempMax = currentSum;
        }
    }
    cout << tempMax << '\n';
}