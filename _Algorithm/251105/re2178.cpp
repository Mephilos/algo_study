#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<vector<int>> visited;
vector<string> maze;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M;

void BFS(int startR, int startC)
{
    queue<pair<int, int>> q;
    q.push({startR, startC});

    visited[startR][startC] = 1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 0 || nc >= M)
            {
                continue;
            }

            if (maze[nr][nc] == '1' && visited[nr][nc] == -1)
            {
                visited[nr][nc] = visited[r][c] + 1;
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

    maze.clear();
    visited.clear();

    maze.resize(N + 1);
    visited.resize(N + 1, vector<int>(M, -1));

    for (int i = 1; i <= N; i++)
    {
        cin >> maze[i];
    }

    BFS(1, 0);

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << visited[N][M - 1] << '\n';
}