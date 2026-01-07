#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int cnt = 1;

    cin >> N >> M;
    while (M != N)
    {
        if (M < N)
        {
            cout << -1 << '\n';
            return 0;
        }
        if (M % 10 == 1)
        {
            M /= 10;
        }
        else if (M % 2 == 0)
        {
            M /= 2;
        }
        else
        {
            cout << -1 << '\n';
            return 0;
        }
        cnt++;
    }
    cout << cnt << '\n';
}