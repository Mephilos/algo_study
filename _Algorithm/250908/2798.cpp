#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    vector<int> pick(N, 0);

    for (int i = 0; i < 3; ++i)
    {
        pick[i] = 1;
    }

    int best = 0;
    sort(pick.begin(), pick.end(), greater<int>());
    
    do {
        int sum = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if (pick[i])
            {
                sum += a[i];
            }
        }
        if (sum > best && sum <= M)
        {
            best = sum;
        }
    } while (prev_permutation(pick.begin(), pick.end()));

    cout << best << "\n";
}