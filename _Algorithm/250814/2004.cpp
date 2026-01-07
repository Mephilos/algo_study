#include <iostream>

using namespace std;

int fac2(long long num)
{
    int op = 0;
    for (long long i = 2; i <= num; i *= 2)
    {
       op += num / i; 
    }
    return op;
}

int fac5(long long num)
{
    int op = 0;
    for (long long i = 5; i <= num; i *= 5)
    {
       op += num / i; 
    }
    return op;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, M, R2 = 0, R5 = 0;
    int result = 0;    
    cin >> N >> M;
    long long mid = N - M;
    R2 = fac2(N);
    R2 -= fac2(mid);
    R2 -= fac2(M);
    R5 = fac5(N);
    R5 -= fac5(N-M);
    R5 -= fac5(M);

    result = R2 > R5 ? R5 : R2;

    cout << result << '\n';
}