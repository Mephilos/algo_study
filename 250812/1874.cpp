#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<char> arr;
    stack<int> stk;
    int count = 1;

    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;
        
        while (count <= target)
        {
            stk.push(count);
            arr.push_back('+');
            count ++;
        }

        if (stk.top() == target)
        {
            stk.pop();
            arr.push_back('-');
        }
        else
        {
            possible = false;
        }
    }
    if (possible)
    {
        for (char a : arr)
        {
            cout << a << '\n';
        }
    }
    else
    {
        cout << "NO\n";
    }
}