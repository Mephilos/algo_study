#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vector<int> alp(26, -1);

    for (int i = 0; i < input.size(); i++)
    {
        int alp_num = input[i] - 'a';
        if (alp[alp_num] == -1)
        {
            alp[alp_num] = i;
        }
    }

    for (int i = 0; i < alp.size(); i++)
    {
        cout << alp[i];
        if (i != 25)
        {
            cout << ' ';
        }
    }   
    cout << '\n';
}