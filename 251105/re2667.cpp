#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<string> land;
vector<vector<int>> danji;
vector<int> dong;
int danjiNum = 1;
int danjiCnt = 0;
int N;
void DFS(int r, int c)
{
    danji[r][c] = danjiNum;
    danjiCnt++;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc > N)
        {
            continue;
        }

        if (danji[nr][nc] == -1 && land[nr][nc] == '1')
        {
            DFS(nr, nc);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    land.resize(N);
    danji.resize(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        cin >> land[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (land[i][j] == '1' && danji[i][j] == -1)
            {
                danjiCnt = 0;
                DFS(i, j);
                dong.push_back(danjiCnt);
                danjiNum++;
            }
        }
    }

    sort(dong.begin(), dong.end());

    cout << danjiNum - 1 << '\n';
    for (int i : dong)
    {
        cout << i << '\n';
    }
}