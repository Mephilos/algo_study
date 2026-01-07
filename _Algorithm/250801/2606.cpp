#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//DFS(깊이 기반 탐색)

// vector<int> graph[101];
// bool visited[101];
// int answer = 0;

// void dfs(int node)
// {
//     visited[node] = true;
//     answer++;

//     for (int i = 0; i < graph[node].size(); i++)
//     {
//         int next_node = graph[node][i];
//         if (!visited[next_node])
//         {
//             dfs(next_node);
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int total_computers;
//     int pairs;

//     cin >> total_computers;
//     cin >> pairs;

//     for (int i = 0; i < pairs; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     dfs(1);

//     if (answer > 0)
//     {
//         cout << answer - 1 << '\n';
//     }else
//     {
//         cout << 0 << '\n';
//     }
// }


// BFS 넓이 기반 탐색
vector<int> graph[101];
bool visited[101];

void bfs(int start_node)
{
    queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    int answer = 0;

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();

        answer++;
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];

            if (!visited[next_node])
            {
                q.push(next_node);
                visited[next_node] = true;
            }
        }
    }

    if (answer > 0)
    {
        cout << answer - 1 << '\n';
    }else
    {
        cout << 0 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total_computers, pairs;
    cin >> total_computers;
    cin >> pairs;

    for (int i = 0; i < pairs; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
}