#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> file;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        int pos = temp.find_last_of('.');
        string x = temp.substr(pos + 1);

        file[x]++;
    }

    for (auto &m : file)
    {
        cout << m.first << ' ' << m.second << '\n';
    }
}