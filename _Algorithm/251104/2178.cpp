#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M;
vector<string> maze;
vector<vector<int>> dist;

void BFS(int startR, int startC)
{
    queue<pair<int, int>> q;
    q.push({startR, startC});
    dist[startR][startC] = 1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            {
                continue;
            }

            if (maze[nr][nc] == '1' && dist[nr][nc] == -1)
            {
                q.push({nr, nc});
                dist[nr][nc] = dist[r][c] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    maze.resize(N);
    dist.resize(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
    {
        cin >> maze[i];
    }
    BFS(0, 0);
    cout << dist[N - 1][M - 1] << '\n';
}