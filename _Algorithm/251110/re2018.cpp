#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int start = 1;
    int currentSum = 0;
    int cnt = 0;

    for (int end = 1; end <= (n / 2) + (n % 2); end++)
    {
        currentSum += end;
        while (currentSum >= n)
        {
            if (currentSum == n)
            {
                cnt++;
            }

            currentSum -= start;
            start++;
        }
    }
    cout << cnt << '\n';
}