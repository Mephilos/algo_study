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
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int currentDir = 0;
    int gameTime = 0;

    int N;
    cin >> N;
    vector<vector<int>> gBoard(N, vector<int>(N));

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int appleR, appleC;
        cin >> appleR >> appleC;
        gBoard[appleR - 1][appleC - 1] = 2;
    }

    int L;
    cin >> L;
    vector<pair<int, char>> cmd;

    for (int i = 0; i < L; i++)
    {
        int time;
        char rota;
        cin >> time >> rota;
        cmd.push_back({time, rota});
    }
    int cmdIdx = 0;

    snake.push_front({0, 0});
    gBoard[0][0] = 1;

    while (true)
    {
        cout << "-- -- -- -- -- --" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << gBoard[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << gameTime << endl;
        cout << cmdIdx << endl;
        gameTime++;
        int hr = snake.front().first;
        int hc = snake.front().second;
        int nr = hr + dr[currentDir];
        int nc = hc + dc[currentDir];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N && gBoard[nr][nc] != 1)
        {
            if (gBoard[nr][nc] == 2)
            {
                snake.push_front({nr, nc});
                gBoard[nr][nc] = 1;
            }
            else
            {
                snake.push_front({nr, nc});
                gBoard[nr][nc] = 1;
                gBoard[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        else
        {
            break;
        }

        if (gameTime == cmd[cmdIdx].first && L > cmdIdx)
        {
            if (cmd[cmdIdx].second == 'L')
            {
                currentDir = (currentDir + 3) % 4;
            }
            else
            {
                currentDir = (currentDir + 1) % 4;
            }

            cmdIdx++;
        }
    }
    cout << gameTime << '\n';
}