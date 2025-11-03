#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    stack<int> stk;
    unsigned int result = 0;

    for (int i = 0; i < K; i++)
    {
        int num;
        cin >> num;

        if (num != 0)
        {
            stk.push(num);
        }
        else
        {
            stk.pop();
        }
    }

    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    cout << result << '\n';
}