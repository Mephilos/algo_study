#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    int result = 0;
    for (int i = 1; i < N; i++ )
    {
        int currentSum = i;
        int temp = i;
        while (temp > 0)
        {
            currentSum += (temp % 10);
            temp /= 10;
        }
        if (N == currentSum)
        {
            result = i;
            break;
        }
    }
    cout << result << '\n';
}