#include <iostream>
#include <stack>
#include <string>

using namespace std;

void StackFnc(string str, stack<int> &stk, int inputNum = 0)
{
    if (str == "push")
    {
        stk.push(inputNum);
    }
    else if (str == "pop")
    {
        if (stk.empty())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << stk.top() << '\n';
            stk.pop();
        }
    }
    else if (str == "size")
    {
        cout << stk.size() << '\n';
    }
    else if (str == "top")
    {
        if (stk.empty())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << stk.top() << '\n';
        }
    }
    else
    {
        cout << stk.empty() << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> stk;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int input;
            cin >> input;
            StackFnc(str, stk, input);
        }
        else
        {
            StackFnc(str, stk);
        }
    }
}