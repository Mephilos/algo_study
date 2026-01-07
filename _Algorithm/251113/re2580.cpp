#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> emptyCell;
bool isPrinted = false;

bool NumCheck(int num, int r, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == num)
        {
            return false;
        }
        if (board[r][i] == num)
        {
            return false;
        }
    }
    for (int j = r - (r % 3); j < r - (r % 3) + 3; j++)
    {
        for (int k = c - (c % 3); k < c - (c % 3) + 3; k++)
        {
            if (board[j][k] == num)
            {
                return false;
            }
        }
    }
    return true;
}
void solve(int z)
{
    if (isPrinted)
        return;

    if (z == emptyCell.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        isPrinted = true;
        return;
    }

    int r = emptyCell[z].first;
    int c = emptyCell[z].second;

    for (int i = 1; i <= 9; i++)
    {
        if (NumCheck(i, r, c))
        {
            board[r][c] = i;
            solve(z + 1);
        }
        if (!isPrinted)
        {
            board[r][c] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                emptyCell.push_back({i, j});
            }
        }
    }
    solve(0);
}