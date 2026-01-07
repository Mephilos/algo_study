#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> num(n);

    iota(num.begin(), num.end(), 1);

    do
    {
        for (const int &i : num)
        {
            cout << i << ' ';
        }
        cout << '\n';
    } while (next_permutation(num.begin(), num.end()));
}