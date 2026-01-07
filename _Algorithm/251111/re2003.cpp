#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int start = 0;
    int sum = 0;
    int cnt = 0;
    for (int end = 0; end < N; end++)
    {
        sum += A[end];

        while (M <= sum)
        {
            if (M == sum)
            {
                cnt++;
            }
            sum -= A[start];
            start++;
        }
    }
    cout << cnt << '\n';
}