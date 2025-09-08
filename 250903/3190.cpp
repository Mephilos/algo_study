#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int current_dir = 0;

    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int> (N, 0));

    deque<pair<int,int>> snake;

    snake.push_back({0,0});
    board[0][0] = 1;

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int apple_coord1, apple_coord2;
        cin >> apple_coord1 >> apple_coord2;
        
        board[apple_coord1-1][apple_coord2-1] = 2;
    }

    int L;
    cin >> L;
    vector<pair<int, char>> commands;

    for (int i = 0; i < L; i++)
    {   
        int X;
        char C; 
        cin >> X >> C;
        commands.push_back({X, C});
    }

    int time = 0;
    int command_index = 0;

    while (true)
    {
        time++;

        int hx = snake.front().first;
        int hy = snake.front().second;
        int nx = hx + dx[current_dir];
        int ny = hy + dy[current_dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 1)
        {
            cout << time << '\n';
            break;
        }

        if (board[nx][ny] != 2)
        {
            int tx = snake.back().first;
            int ty = snake.back().second;

            board[tx][ty] = 0;
            snake.pop_back();
        }

        snake.push_front({nx, ny});
        board[nx][ny] = 1;

        if (command_index < L && commands[command_index].first == time)
        {
            if (commands[command_index].second == 'D')
            {
                current_dir = (current_dir + 1) % 4;
            }
            else
            {
                current_dir = (current_dir + 3) % 4;
            }
            command_index++;
        }
    }
}