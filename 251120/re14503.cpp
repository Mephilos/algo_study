#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> room(N, vector<int>(M));

    int r, c, d;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }
    int cleanCnt = 0;
    while (true)
    {
        bool flag = false;

        if (room[r][c] == 0)
        {
            cleanCnt++;
            room[r][c] = 2;
        }

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            {
                continue;
            }

            if (room[nr][nc] != 1 && room[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }

        int backr = r - dr[d];
        int backc = c - dc[d];

        if (backr >= 0 && backr < N && backc >= 0 && backc < M && room[backr][backc] != 1)
        {
            r = backr;
            c = backc;
        }
        else
        {
            break;
        }
    }
    cout << cleanCnt << '\n';
}