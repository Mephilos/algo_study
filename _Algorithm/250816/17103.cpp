#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> isPrime (1000001, true);

    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int T, N;

    cin >> T;

    for (int i = 0; i < T ; i++)
    {   
        cin >> N;
        int count = 0;
        for (int j = 2; j <= N / 2; j++)
        {
            if (isPrime[j] && isPrime[N - j])
            {
                count++;
            }
        }
        cout << count << '\n';
    }
}