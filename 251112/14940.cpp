#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<int>> land;
vector<vector<int>> dist;
pair<int, int> start;

int n, m;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void BFS()
{
    queue<pair<int, int>> q;

    q.push({start.first, start.second});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }

            if (land[nr][nc] == 1 && dist[nr][nc] == -1)
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
    land.clear();
    land.resize(n, vector<int>(m));
    dist.clear();
    dist.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];

            if (land[i][j] == 2)
            {
                start = {i, j};
                dist[i][j] = 0;
            }
            else if (land[i][j] == 0)
            {
                dist[i][j] = 0;
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}