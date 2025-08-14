#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int S = 0;

    while (M--)
    {
        string com;
        cin >> com;

        if (com == "add")
        {
            int x;
            cin >> x;
            S |= (1 << x);
        }
        else if (com == "remove")
        {
            int x;
            cin >> x;
            S &= ~(1 << x);
        }
        else if (com == "check")
        {
            int x;
            cin >> x;
            if (S & (1 << x))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (com == "toggle")
        {
            int x;
            cin >> x;
            S ^= (1 << x);
        }
        else if (com == "all")
        {
            S = (1 << 21) - 1;
        }
        else if (com == "empty")
        {
            S = 0;
        }
    }
    return 0;
}