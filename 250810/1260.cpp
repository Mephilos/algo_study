#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static int node_num = 0;
void DFS(int start_node);
void BFS(int start_node);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n , m;
        cin >> n >> m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    visited = vector<bool> (N + 1, false);
    
    DFS(V);
    cout << '\n';
    fill(visited.begin(), visited.end(), false);
    BFS(V);
    cout << '\n';

}

void DFS(int v)
{
    cout << v << ' ';
    visited[v] = true;
    for (int i : graph[v])
    {
        if(!visited[i])
        {   
            DFS(i);
        }
    }

}
void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())      
    {
        int temp = q.front();
        cout << temp << ' ';
        q.pop();
        for (int i : graph[temp])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}