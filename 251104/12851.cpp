#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist(100001, -1);
vector<int> counter(100001, 0);

int N, K;
void BFS()
{
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    counter[N] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        int nextPosition[] = {current + 1, current - 1, current * 2};

        for (int next : nextPosition)
        {
            if (next < 0 || next > 100000)
            {
                continue;
            }

            if (dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                counter[next] = counter[current];
                q.push(next);
            }
            else if (dist[next] == dist[current] + 1)
            {
                counter[next] += counter[current];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    if (N == K)
    {
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    BFS();

    cout << dist[K] << '\n';
    cout << counter[K] << '\n';
}