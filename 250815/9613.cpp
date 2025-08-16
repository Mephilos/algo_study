#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int GDC (int num1, int num2)
{
    while (num2 != 0)
    {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    return num1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, n;
    cin >> T;

    vector<int> gcd_input;
    for (int i = 0; i < T; i++)
    {
        long long result = 0;
        cin >> n;
        gcd_input = vector<int> (n);
        for (int j = 0; j < n; j++)
        {
            cin >> gcd_input[j];
        }
        for (int k = 0; k < gcd_input.size(); k++ )
        {
            for (int g = k + 1; g < gcd_input.size(); g++)
            {
                result += GDC(gcd_input[k],gcd_input[g]);
            }
        }
        cout << result << '\n';
    }
    
}