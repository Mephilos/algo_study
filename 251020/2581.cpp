#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> FindPrime(int n)
{
    if (n < 2) return {};

    vector<bool> isPrime(n+1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> result (0);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]) result.push_back(i);
    }

    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;

    cin >> M >> N;

    vector<int> primeNum = FindPrime(N);

    int minValue = -1;
    int sumPrime = 0;

    for (const auto prime : primeNum)
    {
        if (prime >= M)
        {
            sumPrime += prime;
            
            if (minValue == -1) minValue = prime;
        }
    }

    if (minValue == -1)
    {
        cout << minValue << '\n';
    }
    else
    {
        cout << sumPrime << '\n';
        cout << minValue << '\n';
    }
}