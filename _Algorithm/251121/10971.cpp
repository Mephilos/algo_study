#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int INF = 1e9;
int w[11][11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    int minCost = INF;

    do
    {
        if (p[0] != 0)
            break;

        int curCost = 0;
        bool possible = true;

        for (int i = 0; i < n - 1; i++)
        {
            int from = p[i];
            int to = p[i + 1];

            if (w[from][to] == 0)
            {
                possible = false;
                break;
            }
            curCost += w[from][to];
        }

        if (possible)
        {
            int last = p[n - 1];
            int start = p[0];

            if (w[last][start] == 0)
            {
                possible = false;
            }
            else
            {
                curCost += w[last][start];
            }
        }

        if (possible)
        {
            minCost = min(minCost, curCost);
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << minCost << '\n';
}