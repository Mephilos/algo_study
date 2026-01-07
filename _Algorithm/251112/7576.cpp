#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> box;
vector<vector<int>> day;
queue<pair<int, int>> q;

int N, M;

void BFS()
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
            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            {
                continue;
            }

            if (day[nr][nc] == -1 && box[nr][nc] == 0)
            {
                day[nr][nc] = day[r][c] + 1;
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
                day[i][j] = 0;
            }
        }
    }
    BFS();

    int dayMax = 0;
    bool flag = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0 && day[i][j] == -1)
            {
                flag = true;
            }
            dayMax = max(dayMax, day[i][j]);
        }
    }

    if (flag)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dayMax << '\n';
    }
}