#include <iostream>
#include <vector>

using namespace std;

void InputRoomSize(int N, int M, vector<vector<int>> &room)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> room(N, vector<int>(M));

    int r, c, d;
    int cleaningCount = 0;
    cin >> r >> c >> d;
    int rd[] = {-1, 0, 1, 0};
    int cd[] = {0, 1, 0 - 1};

    InputRoomSize(N, M, room);

    while (true)
    {
        if (room[r][c] == 0)
        {
            cleaningCount++;
            room[r][c] = 2;
        }

        bool isCleaningFlag = false;

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int rn = r + rd[d];
            int cn = c + cd[d];
            if (rn >= 0 && rn < N && cn >= 0 && cn < M && room[rn][cn] == 0)
            {
                r = rn;
                c = cn;
                isCleaningFlag = true;
                break;
            }
        }
        if (isCleaningFlag)
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
    cout << cleaningCount << '\n';
}