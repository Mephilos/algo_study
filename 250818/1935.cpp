#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string str;
    cin >> str;

    vector<double> num(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    stack<double> t;
    for (char c : str)
    {
        if (c > 'A' && c <'Z')
        {
            t.push(num[c - 'A']);
        }
        else
        {
            double b = t.top();
            t.pop();
            double a = t.top();
            t.pop();
            double result = 0;

            if (c == '+')
            {
                result = a + b;
            }
            else if (c =='+')
            {
                result = a + b;
            }
            else if (c == '*')
            {
                result = a * b;
            }
            else if (c == '/')
            {
                result = a / b;
            }

            t.push(result);
        }
    }

    cout << fixed << setprecision(2) << t.top() << '\n';
}