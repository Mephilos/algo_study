#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
int N, S;
int answer = 0;
void solve(int n, int sum)
{
    if (n == -1)
    {
        if (sum == S)
        {
            answer++;
        }
        return;
    }

    solve(n - 1, sum + num[n]);
    solve(n - 1, sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    num.resize(N);

    for (int &i : num)
    {
        cin >> i;
    }

    solve(N - 1, 0);

    if (S != 0)
    {
        cout << answer << '\n';
    }
    else
    {
        cout << answer - 1 << '\n';
    }
}