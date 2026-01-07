#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec (N + 1, vector<int>(N + 1));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int tempSum;
            cin >> tempSum;
            vec[i][j] =vec[i][j - 1] + vec[i - 1][j] - vec[i - 1][j - 1] + tempSum;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << vec[x2][y2] - vec[x1 - 1][y2] - vec[x2][y1 - 1] + vec[x1 - 1][y1 - 1] << '\n'; 
    }
}