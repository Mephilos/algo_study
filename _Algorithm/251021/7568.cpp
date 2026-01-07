#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<vector<int>> hamHuman(N, vector<int>(2));

    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < 2; j ++)
        {
            cin >> hamHuman[i][j];
        }
    }

    for (int i = 0; i < N ; i++)
    {
        int rank = 0;

        for (int j = 0 ; j < N; j++)
        {
            if (i == j) continue;
            if (hamHuman[i][0] < hamHuman[j][0] && hamHuman[i][1] < hamHuman[j][1] )
            {
                rank++;
            }
        }
        cout << rank + 1 << ' ';
    }
    cout << '\n';
}