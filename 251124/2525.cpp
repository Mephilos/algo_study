#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> time;
    int cookTime;

    cin >> time.first >> time.second >> cookTime;

    time.second += cookTime;

    time.first += time.second / 60;

    time.second %= 60;

    time.first %= 24;

    cout << time.first << ' ' << time.second << '\n';
}