#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    array<int,3> lines;

    while (true)
    {
        cin >> lines[0] >> lines[1] >> lines[2];

        if (lines[0] == 0 && lines[1] == 0 && lines[2] == 0)
        {
            return 0;
        }
        
        sort(lines.begin(), lines.end());

        if (lines[0]*lines[0] + lines[1]*lines[1] == lines[2]*lines[2])
        {
            cout << "right" << '\n';
        }else
        {
            cout << "wrong" << '\n';
        }
    }
}