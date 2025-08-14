#include <iostream>

using namespace std;

int main()
{
    int num, result;
    cin >> num;
    for (int i = 1; i < 10; i++)
    {
        result = num * i;
        cout << num << " * " << i << " = " << result <<'\n';
    }
}