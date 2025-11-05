#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int maxDot = 100000;

vector<int> subin(maxDot + 1, -1);

void BFS(int N)
{
    queue<int> q;
    q.push(N);
    subin[N] = 0;
    while (!q.empty())
    {
        int dot = q.front();
        q.pop();
        int nextDot = dot + 1;
        if (nextDot <= maxDot && subin[nextDot] == -1)
        {
            subin[nextDot] = subin[dot] + 1;
            q.push(nextDot);
        }
        int nextDot1 = dot - 1;
        if (nextDot1 >= 0 && subin[nextDot1] == -1)
        {
            subin[nextDot1] = subin[dot] + 1;
            q.push(nextDot1);
        }
        int nextDot2 = dot * 2;
        if (nextDot2 <= maxDot && subin[nextDot2] == -1)
        {
            subin[nextDot2] = subin[dot] + 1;
            q.push(nextDot2);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    BFS(N);

    cout << subin[K] << '\n';
}