#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> tempDay(N);
    int tempSum = 0;
    int tempMax = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tempDay[i];
    }

    for (int i = 0; i < K; i++)
    {
        tempSum += tempDay[i];
    }
    tempMax = tempSum;

    for (int i = 0; i < N - K; i++)
    {
        tempSum = tempSum - tempDay[i];
        tempSum = tempSum + tempDay[i + K];

        if (tempMax < tempSum)
        {
            tempMax = tempSum;
        }
    }

    cout << tempMax << '\n';
}