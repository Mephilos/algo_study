#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> beilding;
    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;

        while (!beilding.empty() && beilding.top() <= height)
        {
            beilding.pop();
        }

        result += beilding.size();
        
        beilding.push(height);
    }
    cout << result << '\n';
}