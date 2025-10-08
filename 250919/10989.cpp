#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int count[10001] = {0};

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        ++count[x];
    }

    for (int v = 1; v <= 10000; v++)
    {
        while (count[v]--)
        {
            cout << v << '\n';
        }
    }
}