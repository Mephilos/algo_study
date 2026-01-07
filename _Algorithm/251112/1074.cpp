#include <vector>
#include <iostream>

using namespace std;

int N, r, c, cnt = 0;

void Solve(int start, int qr, int qc)
{

    if (start == 0)
    {
        return;
    }

    int cell = 1 << (start - 1);

    int qdsize = cell * cell;

    if (r < qr + cell && c < qc + cell)
    {
        Solve(start - 1, qr, qc);
    }
    else if (r < qr + cell && c >= qc + cell)
    {
        cnt += qdsize;
        Solve(start - 1, qr, qc + cell);
    }
    else if (r >= qr + cell && c < qc + cell)
    {
        cnt += 2 * qdsize;
        Solve(start - 1, qr + cell, qc);
    }
    else
    {
        cnt += 3 * qdsize;
        Solve(start - 1, qr + cell, qc + cell);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;

    Solve(N, 0, 0);

    cout << cnt << '\n';
}