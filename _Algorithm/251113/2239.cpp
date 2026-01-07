#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<string> board(9);
vector<pair<int, int>> emptyCell;
bool isPrinting = false;

bool Check(int target, int r, int c)
{
    char num = target + '0';
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == num)
            return false;
        if (board[r][i] == num)
            return false;
    }

    int initR = r - (r % 3);
    int initC = c - (c % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + initR][j + initC] == num)
                return false;
        }
    }
    return true;
}

void solve(int z)
{
    if (isPrinting)
        return;
    if (z == emptyCell.size())
    {
        for (auto i : board)
        {
            cout << i << '\n';
        }
        isPrinting = true;
        return;
    }

    int r = emptyCell[z].first;
    int c = emptyCell[z].second;

    for (int i = 1; i <= 9; i++)
    {
        if (Check(i, r, c))
        {
            board[r][c] = (i + '0');

            solve(z + 1);

            if (!isPrinting)
                board[r][c] = '0';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        cin >> board[i];

        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '0')
            {
                emptyCell.push_back({i, j});
            }
        }
    }
    solve(0);
}