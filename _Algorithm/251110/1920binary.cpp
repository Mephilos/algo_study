#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;

        bool find = binary_search(a.begin(), a.end(), temp);

        if (find)
        {
            cout << '1' << '\n';
        }
        else
        {
            cout << '0' << '\n';
        }
    }
}