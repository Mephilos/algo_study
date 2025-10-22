#include <iostream>
#include <vector>

using namespace std;

vector<int> FindPrime(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> result;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> priem = FindPrime(N);

    int minPrime = -1;
    int sumPrime = 0;

    for (const auto& num : priem)
    {
        if (num >= M)
        {
            sumPrime += num;
            if (minPrime == -1)
            {
                minPrime = num;
            }
        }
    }
    if (minPrime == -1)
    {
        cout << minPrime << '\n';
    }
    else
    {
        cout << sumPrime << '\n';
        cout << minPrime << '\n';
    }
}