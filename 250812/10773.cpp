#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int K, result = 0;
    cin >> K;

    stack<int> stk;
    for (int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(temp);
        }
    }

    while (!stk.empty())
    {
        result += stk.top();
        
        stk.pop();
    }
    cout << result << '\n';
}