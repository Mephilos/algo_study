#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    unordered_set<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.insert(temp);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;

        cout << a.count(temp) << '\n';
    }
}