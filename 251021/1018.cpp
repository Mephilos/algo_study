#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m;
    cin >> n >> m;

    vector<string> bw (n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> bw[i];
    }
    int minCount = 64;

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j ++)
        {
            int startW = 0;
            int startB = 0;
            int wbMin = 0;
            for (int k = i; k < i + 8 ; k++)
            {
                for (int r = j; r < j + 8 ;r ++)
                {
                    if ((k + r) % 2 == 0)
                    {
                        if (bw[k][r] == 'W') startB++;
                        if (bw[k][r] == 'B') startW++;
                    }
                    else 
                    {
                        if (bw[k][r] == 'W') startW++;
                        if (bw[k][r] == 'B') startB++;
                    }
                }
            }
            int currentMin = startB > startW ? startW : startB;
            minCount = minCount > currentMin ? currentMin : minCount;
        }
    }
    cout << minCount << '\n';
}