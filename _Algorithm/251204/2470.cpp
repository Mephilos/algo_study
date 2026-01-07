#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
#define endl '\n'

vector<int> liquid;
int N;
int arr[2];
int mindiff = 2000000001;

void Search()
{
    int left = 0;
    int right = N - 1;

    while (left < right)
    {
        int sum = liquid[left] + liquid[right];

        if (mindiff > abs(sum))
        {
            mindiff = abs(sum);

            arr[0] = liquid[left];
            arr[1] = liquid[right];
        }

        if (sum <= 0)
        {
            left++;
        }
        else if (sum > 0)
        {
            right--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    liquid.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    Search();

    cout << arr[0] << ' ' << arr[1] << endl;
}