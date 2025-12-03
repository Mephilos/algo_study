#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> coin(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }
    int cnt = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (coin[i] <= K)
        {
            cnt += (K / coin[i]);
            K = K % coin[i];
        }
    }
    cout << cnt << endl;
}
