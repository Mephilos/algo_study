#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> alpa(26, 0);
    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - 'a' >= 0 && s[i] - 'a' < alpa.size())
        {
            alpa[s[i] - 'a']++;
        }
        else
        {
            alpa[s[i] - 'A']++;
        }
    }
    int maxCnt = 0;
    bool tieFlag = false;
    char al = 0;
    for (int i = 0; i < alpa.size(); i++)
    {
        if (maxCnt < alpa[i])
        {
            maxCnt = alpa[i];
            al = i + 'A';
            tieFlag = false;
        }

        else if (maxCnt == alpa[i])
        {
            tieFlag = true;
        }
    }
    if (tieFlag)
    {
        cout << '?' << '\n';
    }
    else
        cout << al << '\n';
}