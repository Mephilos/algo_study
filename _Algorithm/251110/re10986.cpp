#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> num(n + 1);
    vector<ll> remain(m);

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[i] = (num[i - 1] + temp) % m;

        remain[num[i]]++;
    }

    ll remainCnt = remain[0];
    for (int i = 0; i < m; i++)
    {
        remainCnt += remain[i] * (remain[i] - 1) / 2;
    }
    cout << remainCnt << '\n';
}