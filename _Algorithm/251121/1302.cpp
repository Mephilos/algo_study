#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> sell;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;
        sell[str]++;
    }

    int cnt = 0;
    string answer;
    for (const auto &ms : sell)
    {
        string name = ms.first;
        int cont = ms.second;

        if (cont > cnt)
        {
            answer = name;
            cnt = cont;
        }
    }
    cout << answer << '\n';
}