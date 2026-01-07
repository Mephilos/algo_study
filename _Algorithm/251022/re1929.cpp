#include <iostream>
#include <vector>

using namespace std;

vector<int> FindPrime(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (isPrime[i] == true)
        {
            for(int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> prime;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
        }
    }
    return prime;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    vector<int> prime = FindPrime(N);
    
    for (int i = 0; i < N; i++)
    {
        if (prime[i] >= M)
        {
            cout << prime[i] << '\n';
        }
    }
}