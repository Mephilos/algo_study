#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> land;
vector<vector<bool>> isVisit;
int T, N, M, K;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    isVisit[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = y + dr[i];
        int nc = x + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= M)
        {
            continue;
        }
        if (land[nr][nc] == 1 && !isVisit[nr][nc])
        {
            dfs(nr, nc);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T-- > 0)
    {
        cin >> M >> N >> K;

        land.clear();
        isVisit.clear();
        land.resize(N, vector<int>(M, 0));
        isVisit.resize(N, vector<bool>(M));

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;

            land[y][x] = 1;
        }
        int wormCnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (land[i][j] == 1 && !isVisit[i][j])
                {
                    dfs(i, j);
                    wormCnt++;
                }
            }
        }
        cout << wormCnt << '\n';
    }
}