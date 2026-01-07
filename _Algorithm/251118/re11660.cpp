#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> num(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            num[i][j] = (num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1]) + temp;
        }
    }

    int sum = 0;

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        sum = num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1];

        cout << sum << '\n';
    }
}