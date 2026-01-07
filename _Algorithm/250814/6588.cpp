#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<bool> isPrime(1000001, true);
    
    for (int i = 2; i <= sqrt(1000001); i ++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    while (cin >> n && n != 0)
    {
        bool found = false;
        for (int i = 3; i < n; i+=2)
        {
            if (isPrime[i] && isPrime[n - i])
            {
                cout << n << ' ' <<'=' << ' ' << i << ' ' << '+' << ' ' << n - i << '\n';
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
}