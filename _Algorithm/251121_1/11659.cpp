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
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        num[i] = num[i - 1] + temp;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        int answer;
        cin >> a >> b;

        answer = num[b] - num[a - 1];
        cout << answer << '\n';
    }
}