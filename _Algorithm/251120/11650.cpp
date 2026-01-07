#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> vecP(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vecP[i].first >> vecP[i].second;
    }

    sort(vecP.begin(), vecP.end());

    for (int i = 0; i < n; i++)
    {
        cout << vecP[i].first << ' ' << vecP[i].second << '\n';
    }
}