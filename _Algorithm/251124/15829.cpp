#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int r = 31;
    const int M = 1234567891;

    int L;
    string s;
    cin >> L >> s;

    long long sum = 0;
    long long rP = 1;

    for (int i = 0; i < L; i++)
    {
        int num = s[i] - 'a' + 1;

        sum = (sum + (num * rP)) % M;

        rP = (rP * r) % M;
    }

    cout << sum << '\n';
}