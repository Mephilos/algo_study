#include <queue>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int N, M;
        cin >> N >> M;

        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            q.push({temp, i});
            pq.push(temp);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int value = q.front().first;
            int index = q.front().second;
            q.pop();

            if (pq.top() == value)
            {
                cnt++;
                pq.pop();
                if (index == M)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
            {
                q.push({value, index});
            }
        }
    }
}