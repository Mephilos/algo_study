// 배열로 받고, 최대 값을 갱신하면서 전부 다 순회 해서 가장 높은 합. 3장.
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, max = 0;

    cin >> N >> M;

    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = arr[i] + arr[j] +arr[k];
                if (sum <= M && sum > max)
                {
                    max = sum;
                }
            }
        }
    }
    cout << max << '\n';
}
