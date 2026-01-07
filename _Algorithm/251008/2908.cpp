#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Revs(string& numStr)
{
    stack<char> digits;

    for (char digit : numStr)
    {
        digits.push(digit);
    }

    string revStr = ""; // 결과를 넣어줄 문자열 (초기화)

    while (!digits.empty())
    {
        revStr += digits.top();
        digits.pop();
    }

    return stoi(revStr);
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num1, num2;

    cin >> num1 >> num2;

    int rev1 = Revs(num1);
    int rev2 = Revs(num2);

    cout << (rev1 > rev2 ? rev1 : rev2) << '\n';
}