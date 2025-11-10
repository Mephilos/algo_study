#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;

    vector<int> local(N);
    int high = 0;
    int low = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> local[i];

        if (local[i] > high)
        {
            high = local[i];
        }
    }

    cin >> M;
    ll result = 0;
    while (low <= high)
    {
        ll totalCost = 0;
        int mid = (low + high) / 2;

        for (int i = 0; i < N; i++)
        {
            if (local[i] <= mid)
            {
                totalCost += local[i];
            }
            else
            {
                totalCost += mid;
            }
        }
        if (totalCost <= M)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << result << '\n';
}