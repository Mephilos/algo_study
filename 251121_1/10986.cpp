#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> num(N + 1);
    vector<int> remain(M);
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        num[i] = (num[i - 1] + temp) % M;

        remain[num[i]]++;
    }

    long long cnt = remain[0];

    for (int i = 0; i < M; i++)
    {
        cnt += (long long)remain[i] * (remain[i] - 1) / 2;
    }
    cout << cnt << '\n';
}