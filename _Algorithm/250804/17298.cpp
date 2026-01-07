// 오큰수 골4

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    for (int i = 0; i < N; i++)
    {
        cout << result[i] << " ";
    }
    cout << '\n';
}