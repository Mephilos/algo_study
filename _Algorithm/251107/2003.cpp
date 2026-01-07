#include <iostream>
#include <vector>

using namespace std;

int SumCount(vector<int> num, int target)
{
    int count = 0;
    int currentSum = 0;
    int start = 0;
    int end = 1;
    int N = num.size();

    if (N == 0)
        return 0;

    currentSum = num[start];

    while (start < N)
    {
        if (currentSum == target)
        {
            count++;

            if (end < N)
            {
                currentSum += num[end];
                end++;
            }
            currentSum -= num[start];
            start++;
        }
        else if (currentSum < target)
        {
            if (end < N)
            {
                currentSum += num[end];
                end++;
            }
            else
            {
                currentSum -= num[start];
                start++;
            }
        }
        else if (currentSum > target)
        {
            currentSum -= num[start];
            start++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int sumCnt = 0;
    cin >> N >> M;
    vector<int> num(N);

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sumCnt = SumCount(num, M);

    cout << sumCnt << '\n';
}