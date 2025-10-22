#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int prime;
        bool isPrime = true;

        cin >> prime;

        if (prime < 2)
        {
            continue;
        }

        for (int j = 2; j < prime; j++)
        {
            if (!(prime % j))
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            count++;
        }
    }
    cout << count << '\n';
}