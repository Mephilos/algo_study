#include <stack>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> stk;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
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
    int answer = 0;
    while (!stk.empty())
    {
        answer += stk.top();
        stk.pop();
    }

    cout << answer << '\n';
}