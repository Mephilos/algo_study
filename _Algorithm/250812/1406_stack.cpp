#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    stack<char> left_str;
    stack<char> right_str;

    for (char c : str)
    {
        left_str.push(c);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!left_str.empty())
            {
                right_str.push(left_str.top());
                left_str.pop();
            }
        }
        else if (cmd == 'D')
        {
            if (!right_str.empty())
            {
                left_str.push(right_str.top());
                right_str.pop();
            }
        }
        else if (cmd == 'B')
        {
            if (!left_str.empty())
            {
                left_str.pop();
            }
        }
        else if (cmd == 'P')
        {
            char temp;
            cin >> temp;
            left_str.push(temp);
        }
    }
    while (!left_str.empty())
    {
        right_str.push(left_str.top());
        left_str.pop();
    }
    while (!right_str.empty())
    {
        cout << right_str.top();
        right_str.pop();
    }
    cout << '\n';
}