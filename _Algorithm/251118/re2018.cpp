#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int start = 0;
    int sum = 0;
    int cnt = 0;
    for (int end = 0; end < N; end++)
    {
        sum += end;

        while (sum >= N)
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