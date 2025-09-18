#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

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
    sort(str.begin(), str.end());

    for (auto &s : str)
    {
        cout << s << endl;
    }
}