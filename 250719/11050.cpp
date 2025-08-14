#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    if (K > N / 2)
    {
        K = N - K;
    }

    long long result = 1;
    for (int i = 0; i < K; ++i)
    {
        result *= (N - i);
        result /= (i + 1);
    }

    cout << result << endl;
}