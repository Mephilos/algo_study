// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N >> M;

//     vector<vector<int>> A;
//     vector<int> indegree;

//     A.resize(N+1);
//     indegree.resize(N+1);

//     for (int i = 0; i < M; i++)
//     {
//         int S,E;
//         cin >> S >> E;
//         A[S].push_back(E);
//         indegree[E]++;
//     }

//     queue<int> queue;

//     for (int i = 1; i <= N; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             queue.push(i);
//         }
//     }
//     while (!queue.empty())
//     {
//         int now = queue.front();
//         queue.pop();
//         cout << now << ' ';
//         for (int next : A[now])
//         {
//             indegree[next]--;
//             if (indegree[next] == 0)
//             {
//                 queue.push(next);
//             }
//         }
//     }
// }


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> in_degree(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int currnet_node = q.front();
        q.pop();

        result.push_back(currnet_node);

        for (int next_node : adj[currnet_node])
        {
            in_degree[next_node]--;
            if (in_degree[next_node] == 0)
            {
                q.push(next_node);
            }
        }
    }

    for (auto re : result)
    {
        cout << re << ' ';
    }
    cout << '\n';
}