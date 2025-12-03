#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl '\n'

int N, M;
int MCC = 64;
vector<string> board;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    board.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int WCC = 0;
            int BCC = 0;
            int CCC = 0;

            for (int k = i; k < i + 8; k++)
            {
                for (int r = j; r < j + 8; r++)
                {
                    if ((k + r) % 2 == 0)
                    {
                        if (board[k][r] == 'B')
                            WCC++;
                        if (board[k][r] == 'W')
                            BCC++;
                    }
                    else
                    {
                        if (board[k][r] == 'B')
                            BCC++;
                        if (board[k][r] == 'W')
                            WCC++;
                    }
                }
            }
            if (WCC > BCC)
            {
                CCC = BCC;
            }
            else
            {
                CCC = WCC;
            }

            if (MCC > CCC)
            {
                MCC = CCC;
            }
        }
    }
    cout << MCC << endl;
}