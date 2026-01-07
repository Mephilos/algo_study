#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool Check(vector<ll> &tree, ll &mid, int M)
{
    ll lengthCnt = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        if (tree[i] > mid)
            lengthCnt += tree[i] - mid;
    }

    return lengthCnt >= M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<ll> tree(N);

    ll low = 0, high = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];

        if (high < tree[i])
        {
            high = tree[i];
        }
    }

    ll maxLength = 0;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (Check(tree, mid, M))
        {
            maxLength = mid;

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << maxLength << '\n';
}