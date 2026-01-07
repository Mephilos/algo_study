#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cin >> x;

    sort(num.begin(), num.end());

    int start = 0;
    int end = n - 1;
    int sum = 0;
    int cnt = 0;

    while (start < end)
    {
        sum = num[start] + num[end];

        if (x == sum)
        {
            cnt++;
            end--;
            start++;
        }
        else if (sum > x)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    cout << cnt << '\n';
}