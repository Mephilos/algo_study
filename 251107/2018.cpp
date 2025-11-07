#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;
    int currentSum = 0;
    int start = 1;

    for (int end = 1; end <= n; end++)
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