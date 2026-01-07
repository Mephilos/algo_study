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
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int sum = 0;
    int start = 0;
    int cnt = 0;
    for (int end = 0; end < N; end++)
    {
        sum += num[end];
        while (sum >= M)
        {
            if (M == sum)
            {
                cnt++;
            }

            sum -= num[start];
            start++;
        }
    }

    cout << cnt << '\n';
}