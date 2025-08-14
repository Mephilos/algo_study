// ppAP 문제 골드4 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string stk;

    for (char c : str)
    {
        stk.push_back(c);
        
        if (stk.length() >= 4 && stk.substr(stk.length() - 4) == "PPAP")
        {
            stk.pop_back();
            stk.pop_back();
            stk.pop_back();   
        }
    }
    if (stk == "P")
    {
        cout << "PPAP" << '\n';
    }
    else
    {
        cout << "NP" << '\n';
    }
}