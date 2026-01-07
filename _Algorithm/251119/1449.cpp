#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    vector<int> leaks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> leaks[i];
    }

    sort(leaks.begin(), leaks.end());

    int tapeCount = 0;
    int maxReach = 0;

    for (int i = 0; i < N; i++)
    {
        if (leaks[i] > maxReach)
        {
            tapeCount++;

            maxReach = leaks[i] + L - 1;
        }
    }

    cout << tapeCount << '\n';

    return 0;
}