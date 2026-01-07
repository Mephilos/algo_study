#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int test_case;
    cin >> test_case;
    vector<string> str;
    for (int i = 0; i < test_case; i++)
    {
        string S;
        cin >> S;
        str.push_back(S);
    }
    for (const string& s : str)
    {
        cout << s.front() << s.back() << '\n';
    }
}