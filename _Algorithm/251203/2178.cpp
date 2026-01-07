#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define endl '\n'

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, M;
vector<string> land;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void bfs(int sr, int sc)
{
    q.push({sr, sc});
    dist[sr][sc] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M)
            {
                continue;
            }

            if (dist[nr][nc] == 0 && land[nr][nc] == '1')
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

    land.resize(N);
    dist.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> land[i];
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1] << endl;
}