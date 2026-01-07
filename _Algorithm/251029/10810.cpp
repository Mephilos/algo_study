#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<int> baguni(N + 1);
    for (int i = 1; i <= N; i++)
    {
        baguni[i] = 0;
    }

    while (M-- > 0)
    {
        int i, j, k;

        cin >> i >> j >> k;

        for (int z = i; z <= j; z++)
        {
            baguni[z] = k;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << baguni[i] << '\n';
    }
}