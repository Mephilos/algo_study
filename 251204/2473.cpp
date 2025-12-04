#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
#define endl '\n'

vector<ll> input;
ll mindiff = 3000000001;
int answer[3];
int N;

void ParametricSearch()
{
    for (int i = 0; i < N - 2; i++)
    {
        int left = i + 1;
        int right = N - 1;

        while (left < right)
        {
            ll sum = input[i] + input[left] + input[right];

            if (mindiff > abs(sum))
            {
                mindiff = abs(sum);

                answer[0] = input[i];
                answer[1] = input[left];
                answer[2] = input[right];
            }

            if (sum >= 0)
            {
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    input.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    ParametricSearch();

    for (int i : answer)
    {
        cout << i << ' ';
    }
    cout << endl;
}