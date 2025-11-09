#include <iostream>
#include <vector>

using namespace std;

using LL = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, cnt = 0;
    cin >> n >> m;

    vector<LL> num(n + 1);
    vector<LL> remain(m, 0);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[i] = (num[i - 1] + temp) % m;
        remain[num[i]]++;
    }
    cnt += remain[0];
    for (int i = 0; i < m; i++)
    {
        cnt += remain[i] * (remain[i] - 1) / 2;
    }

    cout << cnt << '\n';
}