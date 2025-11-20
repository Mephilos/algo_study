#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;
vector<string> land;
vector<vector<int>> dist;
queue<pair<int, int>> q;
int n, m;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(int lr, int lc)
{
    dist[lr][lc] = 1;
    q.push({lr, lc});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
            {
                continue;
            }
            if (land[nr][nc] == '1' && dist[nr][nc] == 0)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    land.resize(n);
    dist.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        cin >> land[i];
    }
    bfs(0, 0);

    cout << dist[n - 1][m - 1] << '\n';
}