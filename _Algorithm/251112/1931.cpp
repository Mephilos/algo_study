#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool Compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second < b.second)
        return true;
    if (a.second > b.second)
        return false;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<pair<int, int>> meeting(T);
    for (int i = 0; i < T; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), Compare);
    int lastEnd = 0;
    int cnt = 0;
    for (int i = 0; i < T; i++)
    {
        if (lastEnd <= meeting[i].first)
        {
            cnt++;
            lastEnd = meeting[i].second;
        }
    }

    cout << cnt << '\n';
}