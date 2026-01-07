#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(1000001, true);

void findPrime()
{
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
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    findPrime();

    int N, M;
    cin >> N >> M;

    for (int i = N; i <= M; i++)
    {
        if (isPrime[i])
        {
            cout << i << '\n';
        }
    }
}