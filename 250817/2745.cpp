#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str_N;
    int B;
    cin >> str_N >> B;
    int result=0;
    for (int i = 0; i < str_N.length(); i++)
    {
        char current_char = str_N[i];
        int num_value;
        
        if (current_char >= '0' && current_char <= '9')
        {
            num_value = current_char -'0';
        }
        else
        {
            num_value = current_char - 'A' + 10;
        }
        result = result * B + num_value;
    }
    cout << result << '\n';
}