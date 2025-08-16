#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    if ( str == "0")
    {
        cout << 0 << '\n';
        return 0;
    }
    switch (str[0])
    {
        case '0':
            break;
        case '1':
            cout << "1";
            break;
        case '2':
            cout << "10";
            break;
        case '3':
            cout << "11";
            break;
        case '4':
            cout << "100";
            break;
        case '5':
            cout << "101";
            break;
        case '6':
            cout << "110";
            break;
        case '7':
            cout << "111";
    }
    for (int i = 1; i < str.length(); i++)
    {
        switch (str[i])
        {
            case '0':
                cout << "000";
                break;
            case '1':
                cout << "001";
                break;
            case '2':
                cout << "010";
                break;
            case '3':
                cout << "011";
                break;
            case '4':
                cout << "100";
                break;
            case '5':
                cout << "101";
                break;
            case '6':
                cout << "110";
                break;
            case '7':
                cout << "111";
        }
    }
    cout << '\n';
}