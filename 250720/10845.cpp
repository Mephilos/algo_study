#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        string com;
        cin >> com;

        if (com == "push")
        {
            int num;
            cin >> num;
            Q.push(num);
        }
        if (com == "pop")
        {
            if (Q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        if (com == "size")
        {
            cout << Q.size() << '\n';
        }
        if (com == "empty")
        {
            cout << Q.empty() << '\n';
        }
        if (com == "front")
        {
            if (Q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << Q.front() << '\n';
            }
        }
        if (com == "back")
        {
            if (Q.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << Q.back() << '\n';
            }
        }
    }
}