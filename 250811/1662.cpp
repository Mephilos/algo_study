#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    stack<pair<int, int>> st;

    int current_len = 0;
    int last_digit = 0;

    for (char c : S)
    {
        if (c >= '0' && c <= '9')
        {
            current_len++;
            last_digit = c - '0';
        }
        else if (c == '(')
        {
            current_len--;
            st.push({last_digit, current_len});

            current_len = 0;
        }
        else
        {
            pair<int, int> top = st.top();
            st.pop();

            int multiplier = top.first;
            int prev_len = top.second;

            current_len = prev_len + (multiplier * current_len);
        }
    }
    cout << current_len << '\n';
}