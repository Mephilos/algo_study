#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    list<char> editor(str.begin(), str.end());

    auto cursor = editor.end();

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (cursor != editor.begin())
            {
                cursor--;
            }
        }
        else if (cmd == 'D')
        {
            if (cursor != editor.end())
            {
                cursor++;
            }
        }
        else if (cmd == 'B')
        {
            if (cursor != editor.begin())
            {
                cursor = editor.erase(--cursor);
            }
        }
        else if (cmd == 'P')
        {
            char temp;
            cin >> temp;
            editor.insert(cursor, temp);
        }
    }

    for (char c : editor)
    {
        cout << c;
    }
    cout << '\n';
}