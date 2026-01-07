#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        vector<pair<int, int>> man;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            man.push_back({a, b});
        }

        sort(man.begin(), man.end());

        int passMan = 1;
        int passScore = man[0].second;
        for (int i = 1; i < n; i++)
        {
            auto [a, b] = man[i];
            if (passScore > b)
            {
                passMan++;
                passScore = b;
            }
        }

        cout << passMan << '\n';
    }
}