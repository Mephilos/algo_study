#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int *num = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int minarScore = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        if (num[i] <= num[i - 1])
        {
            minarScore += num[i - 1] - num[i] + 1;
            num[i - 1] = num[i] - 1;
        }
    }

    cout << minarScore << '\n';

    delete[] num;
}