#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    bool YON = true;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        stack<char> stk;
        YON = true;
        for (char c : s)
        {
            if (c == '(')
            {
                stk.push(c);
            }else
            {
                if ( stk.empty() || stk.top() == '(' && c != ')')
                {
                    YON = false;
                    break;
                }
                stk.pop();
            }
        }
        if (!stk.empty())
        {
            YON = false;
        }
        if(YON)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}