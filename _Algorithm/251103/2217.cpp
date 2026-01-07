#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> lof(N);

    for (int i = 0; i < N; i++)
    {
        cin >> lof[i];
    }

    sort(lof.begin(), lof.end());

    int max_ = 0;
    for (int i = 0; i < N; i++)
    {
        max_ = max(max_, lof[i] * (N - i));
    }
    cout << max_ << '\n';
}