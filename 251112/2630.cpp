#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> paper;
int blueCnt = 0;
int whiteCnt = 0;

void Solve(int r, int c, int size)
{
    int _coler = paper[r][c];
    bool isMixed = false;

    for (int i = r; i < size + r; i++)
    {
        for (int j = c; j < size + c; j++)
        {
            if (_coler != paper[i][j])
            {
                isMixed = true;
                break;
            }
        }
        if (isMixed)
            break;
    }

    if (isMixed)
    {
        int newSize = size / 2;

        Solve(r, c, newSize);
        Solve(r, c + newSize, newSize);
        Solve(r + newSize, c, newSize);
        Solve(r + newSize, c + newSize, newSize);
    }

    else
    {
        if (_coler == 0)
        {
            whiteCnt++;
        }
        else
        {
            blueCnt++;
        }
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    paper.clear();
    paper.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    Solve(0, 0, N);

    cout << whiteCnt << '\n';
    cout << blueCnt << '\n';
}