#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, target;
    int count = 0;
    cin >> N >> target;

    vector<int> money(N);
    for (int i = 0; i < N; i++)
    {
        cin >> money[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (target >= money[i])
        {
            count = count + (target / money[i]);
            target = target % money[i];
        }
    }

    cout << count << '\n';
}