#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
int N, K;
vector<int> dist(100001, -1);

void BFS(int n, int k)
{
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        if (temp == k)
        {
            cout << dist[k] << '\n';
            break;
        }

        int next = temp + 1;
        if (next >= 0 && 100000 >= next && dist[next] == -1)
        {
            dist[next] = dist[temp] + 1;
            q.push(next);
        }
        int next2 = temp - 1;
        if (next2 >= 0 && 100000 >= next2 && dist[next2] == -1)
        {
            dist[next2] = dist[temp] + 1;
            q.push(next2);
        }
        int next3 = temp * 2;
        if (next3 >= 0 && 100000 >= next3 && dist[next3] == -1)
        {
            dist[next3] = dist[temp] + 1;
            q.push(next3);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    BFS(N, K);
}