#include <iostream>
#include <vector>

using namespace std;

vector<int> dice(7, 0);
vector<vector<int>> land;

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

void Dice(int dir)
{
    int d1 = dice[1]; // 위
    int d2 = dice[2]; // 북
    int d3 = dice[3]; // 동
    int d4 = dice[4]; // 서
    int d5 = dice[5]; // 남
    int d6 = dice[6]; // 바닥

    if (dir == 1) // 동
    {
        dice[1] = d4;
        dice[3] = d1;
        dice[4] = d6;
        dice[6] = d3;
    }
    else if (dir == 2) // 서
    {
        dice[1] = d3;
        dice[3] = d6;
        dice[4] = d1;
        dice[6] = d4;
    }
    else if (dir == 3) // 북
    {
        dice[2] = d1;
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
    }
    else if (dir == 4) // 남
    {
        dice[2] = d6;
        dice[1] = d2;
        dice[5] = d1;
        dice[6] = d5;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, r, c, K;
    cin >> N >> M >> r >> c >> K;
    land.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> land[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int cmd;
        cin >> cmd;

        int nr = r + dr[cmd];
        int nc = c + dc[cmd];

        if (nr < 0 || nc < 0 || nr >= N || nc >= M)
        {
            continue;
        }

        r = nr;
        c = nc;

        Dice(cmd);

        if (land[r][c] == 0)
        {
            land[r][c] = dice[6];
        }
        else
        {
            dice[6] = land[r][c];
            land[r][c] = 0;
        }

        cout << dice[1] << '\n';
    }
}