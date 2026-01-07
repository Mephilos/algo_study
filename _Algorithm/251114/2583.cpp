#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> board;
vector<vector<bool>> isVisit;

void dfs(int r, int c, int &area)
{
    isVisit[r][c] = true;
    area++;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= M || nc < 0 || nc >= N)
        {
            continue;
        }
        if (!isVisit[nr][nc] && board[nr][nc] == 0)
        {
            dfs(nr, nc, area);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;

    board.resize(M, vector<int>(N));
    isVisit.resize(M, vector<bool>(N));

    while (K-- > 0)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                board[i][j] = 1;
            }
        }
    }
    int area = 0;
    vector<int> areaSize;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0 && !isVisit[i][j])
            {
                int size = 0;
                dfs(i, j, size);
                areaSize.push_back(size);
                area++;
            }
        }
    }

    cout << area << '\n';

    sort(areaSize.begin(), areaSize.end());

    for (int &i : areaSize)
    {
        cout << i << ' ';
    }
    cout << '\n';
}