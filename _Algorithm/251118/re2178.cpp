#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<string> land;
queue<pair<int, int>> q;
vector<vector<int>> dist;
int N, M;

void bfs(int r, int c)
{
    q.push({r, c});
    dist[r][c] = 1;

    while (!q.empty())
    {
        int qr = q.front().first;
        int qc = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = qr + dr[i];
            int nc = qc + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M)
            {
                continue;
            }

            if (land[nr][nc] == '1' && dist[nr][nc] == 0)
            {
                dist[nr][nc] = dist[qr][qc] + 1;
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
    land.resize(N);
    dist.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        cin >> land[i];
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1] << '\n';
}