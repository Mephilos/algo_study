#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int T;

    cin >> T;

    while (T-- > 0)
    {
        string inStk;
        stack<char> stk;
        bool flag = true;
        cin >> inStk;

        for (auto input : inStk)
        {
            if (input == '(')
            {
                stk.push(input);
            }
            else
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (stk.empty() && flag)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}