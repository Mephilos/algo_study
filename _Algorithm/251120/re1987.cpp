#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<int>> box;
vector<vector<int>> day;
queue<pair<int, int>> q;

int M, N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs()
{
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nc >= M || nr >= N)
            {
                continue;
            }
            if (box[nr][nc] == 0 && day[nr][nc] == -1)
            {
                day[nr][nc] = day[r][c] + 1;
                box[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    box.resize(N, vector<int>(M));
    day.resize(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];

            if (box[i][j] == 1)
            {
                q.push({i, j});
                day[i][j] = 0;
            }
            else if (box[i][j] == -1)
            {
                day[i][j] = -2;
            }
        }
    }

    bfs();
    int maxDay = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0 && day[i][j] == -1)
            {
                cout << -1 << '\n';
                return 0;
            }
            maxDay = max(maxDay, day[i][j]);
        }
    }
    cout << maxDay << '\n';
}