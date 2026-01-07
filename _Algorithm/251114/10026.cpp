#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<string> colors;
vector<vector<bool>> check;

void dfs(int r, int c, char cha)
{
    check[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        {
            continue;
        }

        if (!check[nr][nc] && colors[nr][nc] == cha)
        {
            dfs(nr, nc, cha);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    colors.resize(N);
    check.resize(N, vector(N, false));
    for (int i = 0; i < N; i++)
    {
        cin >> colors[i];
    }
    int nonblind = 0;
    int blind = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < colors[i].size(); j++)
        {
            if (colors[i][j] == 'R' && !check[i][j])
            {
                dfs(i, j, 'R');
                nonblind++;
            }
            else if (colors[i][j] == 'G' && !check[i][j])
            {
                dfs(i, j, 'G');
                nonblind++;
            }
            else if (colors[i][j] == 'B' && !check[i][j])
            {
                dfs(i, j, 'B');
                nonblind++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill(check[i].begin(), check[i].end(), false);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < colors[i].size(); j++)
        {
            if (colors[i][j] == 'G')
            {
                colors[i][j] = 'R';
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < colors[i].size(); j++)
        {
            if (colors[i][j] == 'R' && !check[i][j])
            {
                dfs(i, j, 'R');
                blind++;
            }
            else if (colors[i][j] == 'B' && !check[i][j])
            {
                dfs(i, j, 'B');
                blind++;
            }
        }
    }
    cout << nonblind << ' ' << blind << '\n';
}