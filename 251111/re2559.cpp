#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int temp, day;
    cin >> temp >> day;
    int currentTemp = 0;

    vector<int> dayTemp(temp);

    for (int i = 0; i < temp; i++)
    {
        cin >> dayTemp[i];
    }
    for (int i = 0; i < day; i++)
    {
        currentTemp += dayTemp[i];
    }
    int _maxTemp = currentTemp;

    for (int i = 0; i < temp - day; i++)
    {
        currentTemp = currentTemp - dayTemp[i] + dayTemp[i + day];
        if (_maxTemp < currentTemp)
        {
            _maxTemp = currentTemp;
        }
    }
    cout << _maxTemp << '\n';
}