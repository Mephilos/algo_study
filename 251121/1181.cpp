#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();

    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> str(N);

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    sort(str.begin(), str.end(), compare);

    auto it = unique(str.begin(), str.end());

    str.erase(it, str.end());

    for (auto i : str)
    {
        cout << i << '\n';
    }
}