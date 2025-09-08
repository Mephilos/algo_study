#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    int r, c, d;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    int clean_count = 0;

    while (true)
    {
        if (map[r][c] == 0)
        {
            map[r][c] = 2;
            clean_count++;
        }

        bool found_to_clean = false;

        for (int i = 0; i < 4; ++i)
        {
            d = (d + 3) % 4;

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                found_to_clean = true;
                break;
            }
        }

        if (found_to_clean)
        {
            continue;
        }
        
        int back_r = r - dr[d];
        int back_c = c - dc[d];

        if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M && map[back_r][back_c] != 1)
        {
            r = back_r;
            c = back_c;
        }
        else
        {
            break;
        }
    }

    cout << clean_count << '\n';
}