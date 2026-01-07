#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;    
    getline(cin, s);

    bool in_word = false;
    int word_count = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            if (!in_word)
            {
                word_count++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    cout << word_count << '\n';
}