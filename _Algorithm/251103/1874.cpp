#include <stack>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<char> a;
    stack<int> stkSet;

    int count = 1;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        int targetNum;
        cin >> targetNum;

        while (targetNum >= count && flag == true)
        {
            stkSet.push(count);
            a.push_back('+');
            count++;
        }
        if (!stkSet.empty() && targetNum == stkSet.top())
        {
            stkSet.pop();
            a.push_back('-');
        }
        else if (stkSet.top() > targetNum)
        {
            flag = false;
        }
    }
    if (flag == false)
    {
        cout << "NO" << '\n';
    }
    else
    {
        for (auto c : a)
        {
            cout << c << '\n';
        }
    }
}
