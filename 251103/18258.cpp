#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    queue<int> q;
    for (int i = 0; i < T; i++)
    {
        string qInput;
        cin >> qInput;

        if (qInput == "push")
        {
            int inputNum;
            cin >> inputNum;
            q.push(inputNum);
        }

        if (qInput == "pop")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        if (qInput == "size")
        {
            cout << q.size() << '\n';
        }

        if (qInput == "empty")
        {
            cout << q.empty() << '\n';
        }

        if (qInput == "front")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << q.front() << '\n';
            }
        }
        if (qInput == "back")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << q.back() << '\n';
            }
        }
    }
}