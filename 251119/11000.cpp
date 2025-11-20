#include <algorithm>
#include <tuple>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> lesson(n);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> lesson[i].first >> lesson[i].second;
    }

    sort(lesson.begin(), lesson.end());

    pq.push(lesson[0].second);

    for (int i = 1; i < n; i++)
    {
        if (pq.top() <= lesson[i].first)
        {
            pq.pop();
        }
        pq.push(lesson[i].second);
    }

    cout << pq.size() << '\n';
}