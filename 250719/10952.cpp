#include <iostream>

using namespace std;

int main()
{
    int num1, num2, result;
    while(true)
    {
        cin >> num1 >> num2;
        if(num1 + num2 == 0)
        {
            return 0;
        }
        result = num1 + num2;

        cout << result << '\n';
    }
}