#include <iostream>
#include <vector>

using namespace std;

vector<int> FindPrime(int N)
{
    vector<bool> isPrime(N+1,true);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if(isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> res;

    for (int i = 2; i <= N; i ++)
    {
        if (isPrime[i]) res.push_back(i);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> prime = FindPrime(N);

    for (const auto primeNum : prime)
    {
        if (primeNum >= M) cout << primeNum << '\n';
    }
}