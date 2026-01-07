#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N;

    vector<int> card(N);

    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    sort(card.begin(), card.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;

        auto up = upper_bound(card.begin(), card.end(), temp);
        auto down = lower_bound(card.begin(), card.end(), temp);

        int anr = up - down;

        cout << anr << ' ';
    }
    cout << '\n';
}