#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num0 = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;
    int num6 = 0;
    int num7 = 0;
    int num8 = 0;
    int num9 = 0;

    vector<int> vec(3);
    int result = 1;
    for (int i = 0; i < 3; i++)
    {
        cin >> vec[i];
        result *= vec[i];
    }
    string s = to_string(result);
    for (char a : s)
    {
        if (a == '0')
        {
            num0++;
        }
        else if (a == '1')
        {
            num1++;
        }
        else if (a == '2')
        {
            num2++;   
        }
        else if (a == '3')
        {
            num3++;
        }
        else if (a == '4')
        {
            num4++;   
        }
        else if (a == '5')
        {
            num5++;
        }
        else if (a == '6')
        {
            num6++;
        }
        else if (a == '7')
        {
            num7++;
        }
        else if (a == '8')
        {
            num8++;
        }
        else if (a == '9')
        {
            num9++;
        }
    }
    cout << num0 << '\n';
    cout << num1 << '\n';
    cout << num2 << '\n';
    cout << num3 << '\n';
    cout << num4 << '\n';
    cout << num5 << '\n';
    cout << num6 << '\n';
    cout << num7 << '\n';
    cout << num8 << '\n';
    cout << num9 << '\n';
}