#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        
        list<char> keyloger;
        auto cursor = keyloger.begin();

        for (char cmd : str)
        {
            if (cmd == '<')
            {
                if (cursor != keyloger.begin())
                cursor--;
            }
            else if (cmd == '>')
            {
                if (cursor != keyloger.end())
                cursor++;
            }
            else if (cmd == '-')
            {
                if (cursor != keyloger.begin())
                cursor = keyloger.erase(--cursor);
            }
            else
            {
                keyloger.insert(cursor, cmd);
            }
        }
        for (auto c : keyloger)
        {
            cout << c;
        }
        cout << '\n';
    }
}