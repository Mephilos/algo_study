#include <iostream>

using namespace std;

int main()
{
    int N, count = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num < 2)
        {
            continue;
        }
        bool isPrime = true;
        for (int j = 2;j < num; j++)
        {
            if(num % j == 0)
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