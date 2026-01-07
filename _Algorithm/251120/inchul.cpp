#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> man(N);
    for (int i = 0; i < N; i++)
    {
        cin >> man[i];
    }

    sort(man.begin(), man.end());

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += man[j];
        }
    }
    cout << sum << '\n';
}