#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> num;
int sumCnt = 0;
int N, M;

void Solve(int idx, int sum)
{
    if (idx == N)
    {
        if (sum == M)
        {
            sumCnt++;
        }
        return;
    }

    Solve(idx + 1, sum + num[idx]);
    Solve(idx + 1, sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    num.clear();
    num.resize(N);

    for (int &i : num)
    {
        cin >> i;
    }

    Solve(0, 0);

    if (M == 0)
    {
        cout << sumCnt - 1 << '\n';
    }
    else
        cout << sumCnt << '\n';
}
