#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Node, edge;
    int count = 0;
    cin >> Node >> edge;
    A.resize(Node + 1);
    visited = vector<bool> (Node + 1, false);

    for (int i = 0; i < edge ; i++)
    {
        int n,e;
        cin >> n >> e;
        A[n].push_back(e);
        A[e].push_back(n);
    }
    
    for (int i = 1; i <= Node; i++)
    {
        if (!visited[i])
        {
            count++;
            DFS(i);
        }
    }
    cout << count << '\n';
}
void DFS(int v)
{
    if (visited[v])
    {
        return;
    }
    
    visited[v] = true;

    for (int i : A[v])
    {
        if (visited[i] == false)
        {
            DFS(i);
        }
    }
}