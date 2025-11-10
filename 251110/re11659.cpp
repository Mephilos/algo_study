#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> num(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[i] += num[i - 1] + temp;
    }

    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        cout << num[k] - num[j - 1] << '\n';
    }
}