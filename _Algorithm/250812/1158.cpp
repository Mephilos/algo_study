#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    cout << '<';
    while (!q.empty())
    {
        for (int j = 0; j < K; j++)
        {
            if (j == K - 1)
            {
                cout << q.front();
                q.pop();
                if (!q.empty())
                {
                    cout << ", ";
                }
                break;
            }
            q.push(q.front());
            q.pop();
        }
    }
    cout << '>' << '\n';
}