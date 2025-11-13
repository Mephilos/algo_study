#include <iostream>
#include <vector>

using namespace std;

vector<string> alpa;
vector<bool> visitAlpa;
int R, C;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int answer = 0;

void solve(int cnt, int r, int c)
{
    if (cnt > answer)
    {
        answer = cnt;
    }

    visitAlpa[alpa[r][c] - 'A'] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
        {
            continue;
        }

        if (!visitAlpa[alpa[nr][nc] - 'A'])
        {
            visitAlpa[alpa[nr][nc] - 'A'] = true;

            solve(cnt + 1, nr, nc);

            visitAlpa[alpa[nr][nc] - 'A'] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    alpa.resize(R);
    visitAlpa.resize(26);

    for (int i = 0; i < R; i++)
    {
        cin >> alpa[i];
    }

    solve(1, 0, 0);

    cout << answer << '\n';
}