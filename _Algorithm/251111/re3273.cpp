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
    vector<int> num(N);

    for (int &i : num)
    {
        cin >> i;
    }
    sort(num.begin(), num.end());
    int idxs = 0;
    int idxe = N - 1;

    int M;
    cin >> M;
    int cnt = 0;

    while (idxs < idxe)
    {
        int sum = num[idxs] + num[idxe];

        if (sum == M)
        {
            cnt++;
            idxe--;
            idxs++;
        }

        else if (sum > M)
        {
            idxe--;
        }
        else
        {
            idxs++;
        }
    }

    cout << cnt << '\n';
}