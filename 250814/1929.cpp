#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    vector<bool> flag(N + 1, true);
    flag[0] = false;
    flag[1] = false;
    

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (flag[i] == true)
        {
            for (long long j = (long long) i * i; j <= N; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for (int i = M; i <= N; i++)
    {
        if (flag[i])
        {
            cout << i << '\n';
        }
    }
}