#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<int>> land;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void bfs()
{

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            {
                continue;
            }

            if (dist[nr][nc] == 0 && land[nr][nc] == 0)
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

    cin >> N >> M;

    land.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> land[i][j];
            if (land[i][j] == 1)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    int maxDist = 0;
    for (auto i : dist)
        for (auto j : i)
            maxDist = max(maxDist, j);

    cout << maxDist << '\n';
}