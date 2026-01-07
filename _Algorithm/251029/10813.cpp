#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void NoSwap(int &M, vector<int> &N)
{
    while (M-- > 0)
    {
        int i, j, temp;

        cin >> i >> j;
        temp = N[i];
        N[i] = N[j];
        N[j] = temp;
    }
}

void Swap(int &M, vector<int> &baguni)
{
    while (M-- > 0)
    {
        int i, j;

        cin >> i >> j;

        swap(baguni[i], baguni[j]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> baguni(N + 1);

    for (int i = 1; i <= N; i++)
    {
        baguni[i] = i;
    }

    // Swap(M, baguni);
    NoSwap(M, baguni);
    for (int i = 1; i <= N; i++)
    {
        cout << baguni[i];
        if (i != N)
            cout << ' ';
    }
    cout << '\n';
}