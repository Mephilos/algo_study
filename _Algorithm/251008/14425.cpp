#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    unordered_set<string> s;
    string temp_str;

    for (int i = 0; i < N; i++)
    {
        cin >>temp_str;
        s.insert(temp_str);
    }

    int count = 0;

    for (int i = 0; i < M; i++)
    {
        cin >> temp_str;

        if (s.find(temp_str) != s.end())
        {
            count++;
        }
    }

    cout << count << '\n';
}