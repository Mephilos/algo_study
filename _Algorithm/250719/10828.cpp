#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    stack<int> v;
    for (int i = 0; i < N; i++)
    {
        string com;
        cin >> com;

        if (com == "push")
        {  
            int num;
            cin >> num;
            v.push(num);
        }
        else if (com == "pop")
        {
            if (v.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << v.top() << '\n';
                v.pop();
            }
        }
        else if (com == "size")
        {
            cout << v.size() << '\n';
        }
        else if (com == "empty")
        {
            cout << v.empty() << '\n';
        }
        else if (com == "top")
        {
            if (v.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << v.top() << '\n';
            }
            
        }
    }
}