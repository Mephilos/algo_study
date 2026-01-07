#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> time;

    cin >> time.first >> time.second;
    if (time.second < 45)
    {
        time.second += 15;

        if (time.first != 0)
        {
            time.first -= 1;
        }
        else
        {
            time.first = 23;
        }
    }
    else
    {
        time.second -= 45;
    }

    cout << time.first << ' ' << time.second << '\n';
}