#include <iostream>
#include <vector>

using namespace std;

vector<int> PrimeFactorSet()
{   
    int max = 5000000;

    vector<int> primeFactorNum(max + 1);
    
    for (int i = 0; i <= max; i++)
    {
        primeFactorNum[i] = i; 
    }

    for (int i = 2; i * i <= max; i++)
    {
        if (primeFactorNum[i] == i)
        {
            for (int j = i * i; j <= max; j+=i)
            {
                if (primeFactorNum[j] == j)
                {
                    primeFactorNum[j] = i;
                }
            }
        }
    }
    return primeFactorNum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> PFSet = PrimeFactorSet();
    int N;
    cin >> N;

    for (int i = 0; i < N ; i++)
    {
        int k ;
        cin >> k;
        while (k > 1)
        {
            cout << PFSet[k] << ' ';
            k = k/PFSet[k];
        }
        cout << '\n';
    }
}