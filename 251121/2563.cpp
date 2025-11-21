#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<bool>> paper(101, vector<bool>(101, false));
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        int ea = a + 10;
        int eb = b + 10;

        for (int k = a; k < ea; k++)
        {
            for (int r = b; r < eb; r++)
            {
                paper[k][r] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (paper[i][j] == true)
            {
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
}