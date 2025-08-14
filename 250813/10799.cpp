#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string bar;
    stack<char> lset;
    cin >> bar;
    int bar_counter = 0;
    for (int i = 0; i < bar.length(); i++)
    {
        if (bar[i] == '(')
        {
            lset.push(bar[i]);
        }
        else if (bar[i] == ')')
        {
            lset.pop();
            if (bar[i - 1] == '(')
            {
                bar_counter += lset.size();
            }
            else 
            {
                bar_counter += 1;
            }
        }
    }
    cout << bar_counter << '\n';
}