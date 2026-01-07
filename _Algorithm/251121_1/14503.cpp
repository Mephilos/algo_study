#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, M, r, c, d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> r >> c >> d;

    vector<vector<int>> bang(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> bang[i][j];
        }
    }
    int cleanCnt = 0;
    while (true)
    {
        bool cleanFlag = false;
        if (bang[r][c] == 0)
        {
            cleanCnt++;
            bang[r][c] = 2;
        }

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M)
            {
                continue;
            }
            if (bang[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                cleanFlag = true;
                break;
            }
        }
        if (cleanFlag)
        {
            continue;
        }

        int backR = r - dr[d];
        int backC = c - dc[d];

        if (backR > 0 && backC > 0 && backR < N && backC < M && bang[backR][backC] != 1)
        {
            r = backR;
            c = backC;
        }
        else
        {
            break;
        }
    }
    cout << cleanCnt << '\n';
}