#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int SumMin(string &str)
{
    int answer = 0;
    string temp = "";
    bool minusflag = false;

    for (int i = 0; i <= str.length(); i++)
    {

        if (str[i] == '-' || str[i] == '+' || i == str.length())
        {
            int num = stoi(temp);

            if (minusflag)
            {
                answer -= num;
            }
            else
            {
                answer += num;
            }
            if (str[i] == '-')
            {
                minusflag = true;
            }
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    cout << SumMin(str) << '\n';
}