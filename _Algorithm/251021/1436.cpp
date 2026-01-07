#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int sixCount = 0;
    int num = 665;
    while (N > sixCount)
    {
        num++;
        string temp = to_string(num);
        
        
        int loop = 0;
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == '6')
            {
                loop++;
            }
            else
            {
                loop = 0;
            }
            
            
            if (loop == 3)
            {
                sixCount++;
                break;
            }
        }
    }
    cout << num << '\n';
}