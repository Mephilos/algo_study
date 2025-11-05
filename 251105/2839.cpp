#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int count = 0;

    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            count += (N / 5);
            cout << count << '\n';
            return 0;
        }

        N -= 3;
        count++;
    }

    cout << -1 << '\n';
}