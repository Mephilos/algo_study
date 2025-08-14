#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

using edge = pair<int, int>;
const int INF = numeric_limits<int>::max();



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int V, E, K;
    cin >> V >> E >> K;
    
    vector<int> mdistance(V+1);
    vector<vector<edge>> mlist(V+1);
    
    mdistance.assign(V+1,INF);
    
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }
    priority_queue<edge, vector<edge>, greater<edge>> q;

    q.push(make_pair(0, K));
    mdistance[K] = 0;

    while (!q.empty())
    {
        edge current = q.top();
        q.pop();

        int current_cost = current.first;
        int current_node = current.second;
        
        if (mdistance[current_node] < current_cost)
        {
            continue;
        }

        for (int i = 0; i < mlist[current_node].size(); i++)
        {
            edge tmp = mlist[current_node][i];
            int next = tmp.first;
            int value = tmp.second;

            if (mdistance[next] > mdistance[current_node] + value)
            {
                mdistance[next] = value + mdistance[current_node];
                q.push(make_pair(mdistance[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (mdistance[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << mdistance[i] << "\n";
        }
    }
}