#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void Yes_std(vector<int> &baguni, int &M)
{
    while (M-- > 0)
    {
        int i, j;
        cin >> i >> j;

        reverse(baguni.begin() + i, baguni.begin() + (j + 1));
    }
}

void No_std(vector<int> &baguni, int &M)
{
    while (M-- > 0)
    {
        int i, j;

        cin >> i >> j;

        while (i < j)
        {
            int temp;
            temp = baguni[i];
            baguni[i] = baguni[j];
            baguni[j] = temp;

            i++;
            j--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    vector<int> baguni(N + 1);

    for (int i = 0; i <= N; i++)
    {
        baguni[i] = i;
    }

    // Yes_std(baguni, M);
    No_std(baguni, M);
    for (int i = 1; i <= N; i++)
    {
        cout << baguni[i] << '\n';
    }
}