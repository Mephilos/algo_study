#include <iostream>
#include <vector>
#include <queue>
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
        int N, M, printCounter = 0;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++)
        {
            int prio;
            cin >> prio;

            q.push({prio, i});
            pq.push(prio);
        }

        while (!q.empty())
        {
            int printPrio = q.front().first;
            int printIdx = q.front().second;

            q.pop();

            if (pq.top() == printPrio)
            {
                pq.pop();
                printCounter++;

                if (printIdx == M)
                {
                    cout << printCounter << '\n';
                    break;
                }
            }
            else
            {
                q.push({printPrio, printIdx});
            }
        }
    }
}