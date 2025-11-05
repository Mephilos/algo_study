#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> land;
vector<vector<bool>> visited;
int N, M, K;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
void DFS(int i, int j)
{
    visited[i][j] = true;

    for (int z = 0; z < 4; z++)
    {
        int nr = i + dr[z];
        int nc = j + dc[z];

        if (nr < 1 || nr > N || nc < 1 || nc > M || land[nr][nc] != 1)
        {
            continue;
        }

        if (!visited[nr][nc])
        {
            DFS(nr, nc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        int bugCnt = 0;

        cin >> M >> N >> K;

        land.clear();
        visited.clear();
        land.resize(N + 1, vector<int>(M + 1, 0));
        visited.resize(N + 1, vector<bool>(M + 1, false));
        for (int i = 1; i <= K; i++)
        {
            int x, y;
            cin >> x >> y;
            land[y + 1][x + 1] = 1;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (land[i][j] == 1 && !visited[i][j])
                {
                    DFS(i, j);
                    bugCnt++;
                }
            }
        }
        cout << bugCnt << '\n';
    }
}