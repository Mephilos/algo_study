#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

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

    sort(coord.begin(), coord.end(), compare);

    for (auto i : coord)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}