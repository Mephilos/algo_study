#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> sPatterns = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string str;
    cin >> str;

    for (int i = 0; i < sPatterns.size(); i++)
    {
        while (true)
        {
            int idx = str.find(sPatterns[i]);

            if (idx == string::npos)
            {
                break;
            }

            str.replace(idx, sPatterns[i].length(), "#");
        }
    }

    cout << str.length() << '\n';
}