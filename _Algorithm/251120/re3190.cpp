#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int i = 0; i < K; i++)
    {
        int cordX, cordY;
        cin >> cordX >> cordY;
        board[cordX - 1][cordY - 1] = 2;
    }
    deque<pair<int, int>> snake;
    snake.push_back({0, 0});
    board[0][0] = 1;

    int L;
    cin >> L;
    int curD = 1;
    vector<pair<int, char>> cmd;

    for (int i = 0; i < L; i++)
    {
        int num;
        char ch;
        cin >> num >> ch;

        cmd.push_back({num, ch});
    }
    int gameTime = 0;
    int cmdIndx = 0;
    while (true)
    {
        gameTime++;

        int rh = snake.front().first;
        int ch = snake.front().second;

        int rn = rh + dr[curD];
        int cn = ch + dc[curD];

        if (rn < 0 || rn >= N || cn < 0 || cn >= N || board[rn][cn] == 1)
        {
            break;
        }
        if (board[rn][cn] == 2)
        {
            snake.push_front({rn, cn});
            board[rn][cn] = 1;
        }
        else
        {
            snake.push_front({rn, cn});
            board[rn][cn] = 1;
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        if (L > cmdIndx && cmd[cmdIndx].first == gameTime)
        {
            if (cmd[cmdIndx].second == 'L')
            {
                curD = (curD + 3) % 4;
            }
            else
            {
                curD = (curD + 1) % 4;
            }
            cmdIndx++;
        }
    }
    cout << gameTime << '\n';
}