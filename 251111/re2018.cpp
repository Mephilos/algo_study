#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int start = 1;
    int cnt = 0;
    int sum = 0;
    for (int end = 1; end <= N; end++)
    {
        sum += end;
        while (N <= sum)
        {
            if (N == sum)
            {
                cnt++;
            }
            sum -= start;
            start++;
        }
    }
    cout << cnt << '\n';
}