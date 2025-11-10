#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> temp(n);

    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    for (int i = 0; i < k; i++)
    {
        currentSum += temp[i];
    }
    int maxTemp = currentSum;
    for (int i = 0; i < n - k; i++)
    {
        currentSum = currentSum - temp[i] + temp[i + k];

        if (maxTemp < currentSum)
        {
            maxTemp = currentSum;
        }
    }

    cout << maxTemp << '\n';
}