#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- > 0)
    {
        unordered_map<string, int> clothes;
        cin >> n;
        int answer = 1;
        for (int i = 0; i < n; i++)
        {
            string temp, tpye;
            cin >> temp >> tpye;
            clothes[tpye]++;
        }

        for (auto &clothe : clothes)
        {
            answer *= (clothe.second + 1);
        }

        cout << answer - 1 << '\n';
    }
}