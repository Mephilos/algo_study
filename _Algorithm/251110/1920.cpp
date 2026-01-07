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

        bool find = false;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (a[mid] == temp)
            {
                find = true;
                break;
            }
            else if (a[mid] < temp)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

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