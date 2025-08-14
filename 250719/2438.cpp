#include <iostream>

using namespace std;

int main()
{
    int star_num;

    cin >> star_num;

    for (int i = 1; i < star_num + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}