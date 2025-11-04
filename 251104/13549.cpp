#include <iostream>
#include <deque>
#include <vector>
#include <utility>

using namespace std;

vector<int> dist(100001, -1);

void BFS(int n, int k)
{
    deque<int> q;
    q.push_front(n);
    dist[n] = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop_front();

        int next3 = temp * 2;
        if (next3 >= 0 && 100000 >= next3 && dist[next3] == -1)
        {
            dist[next3] = dist[temp];
            q.push_front(next3);
        }
        int next2 = temp - 1;
        if (next2 >= 0 && 100000 >= next2 && dist[next2] == -1)
        {
            dist[next2] = dist[temp] + 1;
            q.push_back(next2);
        }
        int next = temp + 1;
        if (next >= 0 && 100000 >= next && dist[next] == -1)
        {
            dist[next] = dist[temp] + 1;
            q.push_back(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;

    cin >> N >> K;
    if (N == K)
    {
        cout << 0 << '\n';
        return 0;
    }

    BFS(N, K);
    cout << dist[K] << '\n';
}