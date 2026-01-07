#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<double> drinks(N);

    for (int i = 0; i < N; i++)
    {
        cin >> drinks[i];
    }

    sort(drinks.begin(), drinks.end());

    double result = drinks[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        result += drinks[i] / 2;
    }

    cout << result << '\n';

    return 0;
}