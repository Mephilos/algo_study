#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
void DFS(vector<vector<int>> &land, vector<vector<bool>> &bisit, int i, int j, int n, int m)
{
    bisit[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
        {
            continue;
        }

        if (land[nr][nc] == 1 && !bisit[nr][nc])
        {
            DFS(land, bisit, nr, nc, n, m);
        }
    }
}

void BFS(vector<vector<int>> &land, vector<vector<bool>> &bisit, int i, int j, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    bisit[i][j] = true;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }
            if (land[nr][nc] == 1 && !bisit[nr][nc])
            {
                bisit[nr][nc] = true;
                q.push({nr, nc});
            }
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
        int count = 0;

        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> land(N, vector<int>(M, 0));
        vector<vector<bool>> bisit(N, vector<bool>(M, false));

        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            land[b][a] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (land[i][j] == 1 && !bisit[i][j])
                {
                    DFS(land, bisit, i, j, N, M);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
}