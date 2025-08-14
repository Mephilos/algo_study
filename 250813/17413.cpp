#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void print(stack<char>& stack)
{
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }

}
int main()
{
    string S;
    getline(cin,S);
    stack<char> stk;
    bool flag = false;

    for (char cs : S)
    {
        if(cs == '<')
        {
            print(stk);
            flag = true;
            cout << cs;
        }
        else if (cs == '>')
        {
            flag = false;
            cout << cs;
        }

        else if (flag)
        {
            cout << cs;
        }
        else
        {
            if (cs == ' ')
            {
                print(stk);
                cout << cs;
            }
            else
            {
                stk.push(cs);
            }
        }
    }
    print(stk);
    cout << '\n';
}

