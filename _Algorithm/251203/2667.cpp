#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<string> land;
vector<vector<int>> danji;

int num = 1;
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c)
{
    danji[r][c] = num;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= N)
        {
            continue;
        }

        if (land[nr][nc] == '1' && danji[nr][nc] == 0)
        {
            dfs(nr, nc);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    land.resize(N);
    danji.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> land[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (land[i][j] == '1' && danji[i][j] == 0)
            {
                dfs(i, j);
                num++;
            }
        }
    }
    cout << num - 1 << endl;

    vector<int> cnt(num, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 1; k < num; k++)
            {
                if (danji[i][j] == k)
                {
                    cnt[k]++;
                }
            }
        }
    }

    sort(cnt.begin(), cnt.end());

    for (int i = 1; i < num; i++)
    {
        cout << cnt[i] << endl;
    }
}