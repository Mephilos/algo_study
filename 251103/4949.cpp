#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while (true)
    {
        stack<char> stk;
        bool flag = true;
        getline(cin, str);

        if (str == ".")
            break;

        for (char input : str)
        {
            if (input == '(' || input == '[')
            {
                stk.push(input);
            }
            else if (input == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    flag = false;
                    break;
                }
                stk.pop();
            }
            else if (input == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    flag = false;
                    break;
                }
                stk.pop();
            }
        }

        if (stk.empty() && flag)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}