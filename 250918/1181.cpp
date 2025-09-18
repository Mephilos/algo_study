#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const string& a, const string& b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;
    vector<string> str(N);

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    sort(str.begin(), str.end(), Compare);

    str.erase(unique(str.begin(), str.end()), str.end());

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << '\n';
    }
}