#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string str;

    cin >> str;

    for (char &c : str)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }else if(islower(c))
        {
            c = toupper(c);
        }
    }

    cout << str << '\n';

}