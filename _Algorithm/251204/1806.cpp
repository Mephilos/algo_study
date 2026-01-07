#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define endl '\n'

vector<int> num;
int N, S;
int mindiff = 1000000001;

void Search()
{
    int start = 0;

    for (int end = 1; end <= N; end++)
    {
        long long sum = num[end] - num[start];

        while (sum >= S)
        {
            mindiff = min(mindiff, end - start);
            start++;
            sum = num[end] - num[start];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    num.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        num[i] = num[i - 1] + temp;
    }

    Search();

    if (mindiff == 1000000001)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << mindiff << endl;
    }
}