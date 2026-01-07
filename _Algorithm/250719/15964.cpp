#include <iostream>

using namespace std;

long long GolbangE(long A, long B)
{
    return (A+B)*(A-B);
}

int main()
{
    long long num1, num2;
    cin >> num1 >> num2;

    cout << GolbangE(num1, num2) << '\n';
    
}