#include <iostream>
#include <vector>

using namespace std;

int SumCounter(vector<int> num, int N, int M)
{
    int start = 0;
    int cnt = 0;
    int currentSum = 0;

    for (int end = 0; end < N; end++)
    {
        currentSum += num[end];

        while (currentSum >= M)
        {
            if (currentSum == M)
            {
                cnt++;
            }
            currentSum -= num[start];
            start++;
        }
    }
    return cnt;
}

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
    int cnt = SumCounter(num, N, M);

    cout << cnt << '\n';
}