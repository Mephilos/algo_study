#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> gameBoard(9, vector<int>(9));
vector<pair<int, int>> emptyCell;
bool isPrinted = false;

bool NumCheck(int r, int c, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (gameBoard[i][c] == num)
        {
            return false;
        }
        if (gameBoard[r][i] == num)
        {
            return false;
        }
    }

    for (int k = 0; k < 3; k++)
    {
        for (int g = 0; g < 3; g++)
        {
            if (gameBoard[r - (r % 3) + k][c - (c % 3) + g] == num)
            {
                return false;
            }
        }
    }
    return true;
}
void Solve(int k)
{
    if (isPrinted)
        return;

    if (k == emptyCell.size())
    {
        for (auto i : gameBoard)
        {
            for (auto j : i)
            {
                cout << j << ' ';
            }
            cout << '\n';
        }
        isPrinted = true;
        return;
    }

    int r = emptyCell[k].first;
    int c = emptyCell[k].second;

    for (int num = 1; num <= 9; num++)
    {
        if (NumCheck(r, c, num))
        {
            gameBoard[r][c] = num;
            Solve(k + 1);

            if (!isPrinted)
                gameBoard[r][c] = 0;
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
            cin >> gameBoard[i][j];

            if (gameBoard[i][j] == 0)
            {
                emptyCell.push_back({i, j});
            }
        }
    }
    Solve(0);
}