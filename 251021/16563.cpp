#include <iostream>
#include <vector>

using namespace std;

vector<int> PrimeFactorSet ()
{
    int max = 5000000;
    vector<int> numPrime(max + 1);

    for (int i = 0; i <= max; i++)
    {
        numPrime[i] = i;
    }

    for (int i = 2; i * i <= max; i++)
    {
        if (numPrime[i] == i)
        {
            for (int j = i * i; j <=max; j+=i)
            {
                if (numPrime[j] == j) 
                {
                    numPrime[j] = i;
                }
            }
        }   
    }
    
    return numPrime;
}

void PrimeFactorization(int N, vector<int> &primeNum)
{
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;

        while (k > 1)
        {
            cout << primeNum[k] << ' ';
            k /= primeNum[k];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primeNum = PrimeFactorSet();

    int N;
    cin >> N;

    PrimeFactorization(N, primeNum);
}
