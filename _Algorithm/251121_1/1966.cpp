#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct print
{
    int main;
    int num;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        priority_queue<int> pq;
        queue<print> q;

        int N, M;
        cin >> N >> M;
        int printCnt = 0;
        for (int i = 0; i < N; i++)
        {
            int prio;
            cin >> prio;

            pq.push(prio);
            q.push({prio, i});
        }

        while (!q.empty())
        {
            int pri = q.front().main;
            int prinNum = q.front().num;

            q.pop();
            if (pq.top() == pri)
            {
                printCnt++;
                if (prinNum == M)
                {
                    break;
                }
                pq.pop();
            }
            else
            {
                q.push({pri, prinNum});
            }
        }
        cout << printCnt << '\n';
    }
}