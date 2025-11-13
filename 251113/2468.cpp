#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 0;
vector<vector<int>> land;
vector<vector<bool>> isVisited;

void dfs(int r, int c, int h)
{
    isVisited[r][c] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        {
            continue;
        }
        if (land[nr][nc] > h && !isVisited[nr][nc])
        {
            dfs(nr, nc, h);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    land.resize(N, vector<int>(N));
    isVisited.resize(N, vector<bool>(N));

    int height = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> land[i][j];

            height = max(height, land[i][j]);
        }
    }

    for (int h = 0; h <= height; h++)
    {
        int safeArea = 0;
        for (int i = 0; i < N; i++)
        {
            fill(isVisited[i].begin(), isVisited[i].end(), false);
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (land[i][j] > h && isVisited[i][j] == false)
                {
                    dfs(i, j, h);
                    safeArea++;
                }
            }
        }
        answer = max(answer, safeArea);
    }
    cout << answer << '\n';
}