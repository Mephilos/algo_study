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
    cin >> N >> M;
    vector<int> num(N + 1);
    vector<int> remain(M);
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        num[i] = (num[i - 1] + temp) % M;

        remain[num[i]]++;
    }
    ll cnt = remain[0];
    for (int i = 0; i < M; i++)
    {
        cnt += (ll)remain[i] * (remain[i] - 1) / 2;
    }

    cout << cnt << '\n';
}