#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, r, c, d;

    int rd[] = {-1, 0, 1, 0};
    int cd[] = {0, 1, 0, -1};

    cin >> N >> M;
    cin >> r >> c >> d;
    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    int clerningCount = 0;
    while (true)
    {
        if (room[r][c] == 0)
        {
            clerningCount++;
            room[r][c] = 2;
        }

        bool isCleaning = false;
        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int nr = r + rd[d];
            int nc = c + cd[d];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && room[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                isCleaning = true;
                break;
            }
        }
        if (isCleaning)
        {
            continue;
        }

        int backr = r - rd[d];
        int backc = c - cd[d];
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
    cout << clerningCount << '\n';
}