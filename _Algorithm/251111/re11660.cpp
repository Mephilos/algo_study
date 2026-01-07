#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> pyo(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            pyo[i][j] = (pyo[i - 1][j] + pyo[i][j - 1] - pyo[i - 1][j - 1]) + temp;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        sum = pyo[x2][y2] - pyo[x1 - 1][y2] - pyo[x2][y1 - 1] + pyo[x1 - 1][y1 - 1];
        cout << sum << '\n';
    }
}