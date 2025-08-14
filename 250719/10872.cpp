#include <iostream>

using namespace std;

long long Fac (int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * Fac(n-1);
}
//연산은 재귀가 끝나고 순차 연산

int main()
{
    int facto;
    long long facto_result;
    
    cin >> facto;
    
    facto_result = Fac(facto);
    
    cout << facto_result << '\n';
}