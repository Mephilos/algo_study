#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dh[] = {0, 0, 0, 0, 1, -1};
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int N, M, H;
vector<vector<vector<int>>> box;
vector<vector<vector<int>>> day;
queue<tuple<int, int, int>> q;

void bfs()
{
    while (!q.empty())
    {
        // int r = get<0>(q.front());
        // int c = get<1>(q.front());
        // int h = get<2>(q.front());
        auto [r, c, h] = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nh = h + dh[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || nh < 0 || nh >= H)
            {
                continue;
            }
            if (box[nr][nc][nh] == 0 && day[nr][nc][nh] == -1)
            {
                day[nr][nc][nh] = day[r][c][h] + 1;
                q.push({nr, nc, nh});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;

    box.resize(N, vector<vector<int>>(M, vector<int>(H, 0)));
    day.resize(N, vector<vector<int>>(M, vector<int>(H, 0)));

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    q.push({i, j, k});
                    day[i][j][k] = 0;
                }
                else if (box[i][j][k] == 0)
                {
                    day[i][j][k] = -1;
                }
            }
        }
    }
    bfs();

    int maxDay = 0;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (day[i][j][k] == -1)
                {
                    flag = false;
                }
                maxDay = max(maxDay, day[i][j][k]);
            }
        }
    }
    if (!flag)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << maxDay << '\n';
    }
}