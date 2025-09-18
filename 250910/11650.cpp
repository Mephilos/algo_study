#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> coord(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }

    sort(coord.begin(), coord.end());

    for (auto &n : coord)
    {
        cout << n.first << ' ' << n.second << '\n';
    }

}