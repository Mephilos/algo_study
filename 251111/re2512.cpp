#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> budget(N);
    for (int &i : budget)
    {
        cin >> i;
    }

    cin >> M;

    int lo = 0;
    int hi = *max_element(budget.begin(), budget.end());
    int answer = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        ll totalBudget = 0;
        for (int i = 0; i < N; i++)
        {
            if (budget[i] <= mid)
            {
                totalBudget += budget[i];
            }
            else
            {
                totalBudget += mid;
            }
        }
        if (totalBudget <= M)
        {
            answer = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << answer << '\n';
}