#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> num(N);
    int start = 0;
    int currentSum = 0;
    int sumCnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    for (int end = 0; end < N; end++)
    {
        currentSum += num[end];
        while (M <= currentSum)
        {
            if (M == currentSum)
            {
                sumCnt++;
            }
            currentSum -= num[start];
            start++;
        }
    }

    cout << sumCnt << '\n';
}