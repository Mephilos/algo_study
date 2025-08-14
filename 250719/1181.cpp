#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    int min = 0;
    cin >> N;
    vector<string> str(N);

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    sort(str.begin(),str.end(), compare);

    auto last = unique(str.begin(), str.end());

    str.erase(last, str.end());

    for (const auto& word : str)
    {
        cout << word << '\n';
    }
}