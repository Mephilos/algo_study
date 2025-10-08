#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int Rev_num(int n)
{
    int revnum = 0;
    while(n > 0)
    {
        int digit = n % 10;
        revnum = revnum * 10 + digit;
        n /= 10;
    }
    return revnum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num(2);
    vector<int> result;
    for (int i = 0; i < 2; i++)
    {
        cin >> num[i];
        result.push_back(Rev_num(num[i]));
    }

    cout << max(result[0], result[1])<< "\n";
}