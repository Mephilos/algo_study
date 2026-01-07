#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, R = 0;
    cin >> N;

    for (int i = 5; i <= N; i *= 5)
    {
        R += N / i;
    }
    cout << R << '\n';
}