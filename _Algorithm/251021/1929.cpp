#include <iostream>
#include <vector>

using namespace std;

vector<int> FindPriem(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

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
    vector<int> res;

    for (int i = 2; i <= n ; i++)
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

    vector<int> prime = FindPriem(N);

    for (const auto& num : prime)
    {
        if (num >= M)
        {
            cout << num << '\n';
        }
    }
}