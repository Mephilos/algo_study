#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
    stack<int> s;
    int N;

    cin >> N;
    vector<int> v(N);
    vector<int> result(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= v[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = s.top();
        }
        s.push(v[i]);
    }

    for (int i = 0; i < N; i ++)
    {
        cout << result[i] << ' ';
    }
    cout << '\n';
}
