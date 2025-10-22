#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int GDC(int a, int b)
{
    if (b == 0) return a;
    
    return GDC (b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int numCount;
        cin >> numCount;
        vector<int> num(numCount, 0);
        long long sumGDC = 0;

        for (int j = 0; j < numCount; j++)
        {
            cin >> num[j];
        }

        for (int k = 0; k <num.size(); k++)
        {
            for (int g = k + 1; g < num.size(); g++)
            {
                sumGDC += GDC(num[k],num[g]);
            }
        }

        cout << sumGDC << '\n';
    }
}