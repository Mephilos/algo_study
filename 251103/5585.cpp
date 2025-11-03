#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;

    int arr[6] = {1, 5, 10, 50, 100, 500};

    int nedan;
    cin >> nedan;

    nedan = 1000 - nedan;

    for (int i = 5; i >= 0; i--)
    {
        if (nedan / arr[i] > 0)
        {
            count += (nedan / arr[i]);
            nedan %= arr[i];
        }
    }
    cout << count << '\n';
}