#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int min_counts = 64;

    for (int r = 0; r <= N - 8; r++)
    {
        for (int c = 0; c <= M - 8; ++c)
        {
            int board_start_W = 0;
            int board_start_B = 0;
            
            for (int i = r; i < r + 8; i++)
            {
                for (int j = c; j < c + 8; j++)
                {
                    if ((i + j) % 2 == 0)
                    {
                        if (board[i][j] != 'W') board_start_W++;
                        if (board[i][j] != 'B') board_start_B++;
                    }else
                    {
                        if (board[i][j] != 'B') board_start_W++;
                        if (board[i][j] != 'W') board_start_B++;
                    }
                }
            }

            int current_min = min(board_start_W, board_start_B);

            if (current_min < min_counts)
            {
                min_counts = current_min;
            }
        }
    }
    cout << min_counts << endl;
}