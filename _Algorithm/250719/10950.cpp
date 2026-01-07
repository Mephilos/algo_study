#include <iostream>

using namespace std;
int main()
{
    int T, num1, num2, result;

    cin >> T;

    for (int i = 1; i < T + 1; i++)
    {
        cin >> num1 >> num2;
        result = num1 + num2;
        cout << result << '\n';
    }
}