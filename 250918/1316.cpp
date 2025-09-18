#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGroupWord(const string& s)
{
    vector<bool> look(26, false);
    char a = '\0';

    for (size_t i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c != a)
        {
            int index = c - 'a';
            if (look[index])
            {
                return false;
            }
            look[index] = true;
            a = c;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;
    
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (isGroupWord(s))
        {
            count++;
        }
    }

    cout << count << '\n';
}