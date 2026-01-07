// #include <iostream>

// using namespace std;

// int gcd(int a, int b) 
// {
//     if (b == 0) {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// int main() 
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int a, b;
//     cin >> a >> b;

//     // 1. 최대공약수(GCD) 계산
//     int g = gcd(a, b);

//     // 2. 최소공배수(LCM) 계산
//     // 공식: 두 수의 곱 = 최대공약수 * 최소공배수
//     int l = (a * b) / g;

//     // 결과 출력
//     cout << g << '\n';
//     cout << l << '\n';

//     return 0;
// }

#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num1, num2;
    cin >> num1 >> num2;
    int g = gcd(num1, num2);
    int l = lcm(num1, num2);

    cout << g << '\n';
    cout << l << '\n';
}