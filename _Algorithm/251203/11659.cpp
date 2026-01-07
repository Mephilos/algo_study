#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> sum(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;

        sum[i] = sum[i - 1] + temp;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
}