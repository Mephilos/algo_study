#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int printingCount = 0;
        for (int i = 0; i < N; i++)
        {
            int prio;
            cin >> prio;

            q.push({prio, i});
            pq.push(prio);
        }

        while (!q.empty())
        {
            int prioValue = q.front().first;
            int idx = q.front().second;
            q.pop();

            if (pq.top() == prioValue)
            {
                printingCount++;
                pq.pop();

                if (idx == M)
                {
                    cout << printingCount << '\n';
                    break;
                }
            }
            else
            {
                q.push({prioValue, idx});
            }
        }
    }
}