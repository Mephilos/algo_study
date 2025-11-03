#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long S;
    cin >> S;

    long long N = 0;
    long long temp = 1;
    long long count = 0;
    while (true)
    {
        count++;
        N += temp;
        temp++;

        if (N > S)
        {
            count--;
            break;
        }
        else if (N == S)
        {
            break;
        }
    }

    cout << count << '\n';
}