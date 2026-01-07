#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> sumNum(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        int temp;

        cin >> temp;

        sumNum[i] = sumNum[i - 1] + temp;
    }

    for (int s = 0; s < M; s++)
    {
        int i, j;
        cin >> i >> j;

        cout << sumNum[j] - sumNum[i - 1] << '\n';
    }
}