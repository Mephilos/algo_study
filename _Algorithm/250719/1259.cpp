#include <string>
#include <iostream>

using namespace std;

int main()
{
    string perin;
    
    while (true)
    {
        cin >> perin;

        if (perin == "0")
        {
            return 0;
        }
        bool perinBool = true;

        for (int i = 0; i < perin.size() / 2; i ++)
        {
            if (perin[i] != perin[perin.size() - 1 - i])
            {
                perinBool = false;
                break;
            }
        }

        if(perinBool)
        {
            cout << "yes" << '\n';
        }else
        {
            cout << "no" << '\n';
        }
    }
}