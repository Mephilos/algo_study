#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec(10, 0);
    string s;
    int max_num= 0;
    cin >> s;
    
    for (char a : s)
    {
        int a_num = a - '0';
        
        if (a_num == 9)
        {
            vec[6]++;
        }
        else 
        {
            vec[a_num]++;
        }
    }
    int temp = vec[6];
    vec[6] = (temp % 2) + (temp / 2);
    
    max_num = *max_element(vec.begin(), vec.end());
    cout << max_num << '\n';
}