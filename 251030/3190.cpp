#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> snake;
    int N, K;

    cin >> N;
    cin >> K;
    vector<vector<int>> room(N, vector<int>(N));

    int rd[] = {0, 1, 0, -1};
    int cd[] = {1, 0, -1, 0};
    int currentD = 0;

    snake.push_front({0, 0});
    room[0][0] = 1;

    int gametime = 0;

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        room[r - 1][c - 1] = 3;
    }

    int L;
    cin >> L;
    vector<pair<int, char>> cmds;
    for (int i = 0; i < L; i++)
    {
        int s;
        char a;
        cin >> s >> a;
        cmds.push_back({s, a});
    }

    int cmdIdx = 0;

    while (true)
    {
        gametime++;

        int rh = snake.front().first;
        int ch = snake.front().second;

        int rn = rh + rd[currentD];
        int cn = ch + cd[currentD];

        if (rn >= 0 && rn < N && cn >= 0 && cn < N && room[rn][cn] != 1)
        {
            if (room[rn][cn] == 3)
            {
                snake.push_front({rn, cn});
                room[rn][cn] = 1;
            }
            else
            {
                snake.push_front({rn, cn});
                room[rn][cn] = 1;
                room[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        else
        {
            break;
        }

        if (cmdIdx < L && gametime == cmds[cmdIdx].first)
        {
            if (cmds[cmdIdx].second == 'L')
            {
                currentD = (currentD + 3) % 4;
            }
            else
            {
                currentD = (currentD + 1) % 4;
            }
            cmdIdx++;
        }
    }
    cout << gametime << '\n';
}