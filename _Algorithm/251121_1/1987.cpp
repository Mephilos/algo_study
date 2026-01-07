#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> isVisit;
vector<string> land;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 0;
int R, C;

void solve(int cnt, int r, int c)
{
    if (answer < cnt)
    {
        answer = cnt;
    }

    isVisit[land[r][c] - 'A'] = true;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= R || nc >= C)
        {
            continue;
        }
        if (!isVisit[land[nr][nc] - 'A'])
        {
            isVisit[land[nr][nc] - 'A'] = true;

            solve(cnt + 1, nr, nc);

            isVisit[land[nr][nc] - 'A'] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    isVisit.resize(26);
    land.resize(R);

    for (int i = 0; i < R; i++)
    {
        cin >> land[i];
    }
    solve(1, 0, 0);

    cout << answer << '\n';
}