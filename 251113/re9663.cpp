#include <iostream>
#include <vector>

using namespace std;

int N, answer = 0;

vector<bool> col;
vector<bool> diag1;
vector<bool> diag2;

void solve(int r)
{
    if (r == N)
    {
        answer++;
        return;
    }

    for (int c = 0; c < N; c++)
    {
        int _diag1 = r + c;
        int _diag2 = (r - c) + (N - 1);

        if (col[c] || diag1[_diag1] || diag2[_diag2])
        {
            continue;
        }

        col[c] = true;
        diag1[_diag1] = true;
        diag2[_diag2] = true;

        solve(r + 1);

        col[c] = false;
        diag1[_diag1] = false;
        diag2[_diag2] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    col.resize(N);
    diag1.resize(N * 2);
    diag2.resize(N * 2);

    solve(0);

    cout << answer << '\n';
}