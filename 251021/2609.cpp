#include <iostream>

using namespace std;


int GDC(int b, int a)
{
    if (a == 0) return b;

    return GDC(a, b % a);
}

int LCM(int a, int b)
{
    int lcm;
    lcm = (a * b) / GDC(a, b);
    return lcm;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;

    cout << GDC(n1, n2) << endl;
    cout << LCM(n1, n2) << endl;
    
}