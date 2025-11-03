#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> road(N - 1);
    queue<int> oilValue;
    long long sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        oilValue.push(value);
    }

    int min = oilValue.front();
    oilValue.pop();

    for (int i = 0; i < N - 1; i++)
    {
        sum += ((long long)road[i] * min);

        if (min <= oilValue.front())
        {
            oilValue.pop();
        }
        else
        {
            min = oilValue.front();
            oilValue.pop();
        }
    }
    cout << sum << '\n';
}