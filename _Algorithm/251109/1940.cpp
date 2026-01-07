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
    vector<int> part(N);

    for (int i = 0; i < N; i++)
    {
        cin >> part[i];
    }

    sort(part.begin(), part.end());

    int idxS = 0;
    int idxE = N - 1;
    int cnt = 0;

    while (idxS > idxE)
    {
        int sum = part[idxS] + part[idxE];

        if (sum == M)
        {
            cnt++;
            idxS++;
            idxE--;
        }
        else if (sum > M)
        {
            idxE--;
        }
        else if (sum < M)
        {
            idxS++;
        }
    }
    cout << cnt << '\n';
}