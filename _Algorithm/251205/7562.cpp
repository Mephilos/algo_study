#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> board;
vector<vector<int>> dist;

int T, N;

void bfs(int cdr, int cdc, int anr, int anc)
{
    queue<pii> q;
    q.push({cdr, cdc});
    dist[cdr][cdc] = 0;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == anr && c == anc)
            return;

        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
            {
                continue;
            }
            if (dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        board.clear();
        dist.clear();

        cin >> N;

        board.resize(N, vector<int>(N, 0));
        dist.resize(N, vector<int>(N, -1));

        int cdR, cdC, anr, anc;
        cin >> cdR >> cdC >> anr >> anc;

        bfs(cdR, cdC, anr, anc);

        cout << dist[anr][anc] << endl;
    }
}