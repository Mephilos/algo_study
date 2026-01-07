#include <iostream>
#include <vector>
#include <deque>

using namespace std;
struct Pair
{
    int first;
    int second;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<Pair> sum;

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        while (!sum.empty() && sum.back().first > temp)
        {
            sum.pop_back();
        }
        sum.push_back({temp, i});
        if (sum.front().second <= i - L)
        {
            sum.pop_front();
        }
        cout << sum.front().first << ' ';
    }
    cout << '\n';
}