#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> land;
vector<vector<bool>> bc;

int T;
int N, M, K;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int s, int g)
{
    bc[s][g] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = s + dr[i];
        int nc = g + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= M)
        {
            continue;
        }
        if (!bc[nr][nc] && land[nr][nc] == 1)
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
        bc.clear();
        land.resize(N, vector<int>(M, 0));
        bc.resize(N, vector<bool>(M));

        for (int i = 0; i < K; i++)
        {
            int temp, temp2;
            cin >> temp >> temp2;

            land[temp2][temp] = 1;
        }
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (land[i][j] == 1 && !bc[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}