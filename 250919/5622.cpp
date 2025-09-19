#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string alpa;

    cin >> alpa;
    int num_sum = 0;
    for (char alpa_num : alpa)
    {
        if (alpa_num == 'A' || alpa_num == 'B' || alpa_num == 'C')
        {
            num_sum += 3;
        }
        else if (alpa_num == 'D' || alpa_num == 'E' || alpa_num == 'F')
        {
            num_sum += 4;
        }
        else if (alpa_num == 'G' || alpa_num == 'H' || alpa_num == 'I')
        {
            num_sum += 5;
        }
        else if (alpa_num == 'J' || alpa_num == 'K' || alpa_num == 'L')
        {
            num_sum += 6;
        }
        else if (alpa_num == 'M' || alpa_num == 'N' || alpa_num == 'O')
        {
            num_sum += 7;
        }
        else if (alpa_num == 'P' || alpa_num == 'Q' || alpa_num == 'R' || alpa_num == 'S')
        {
            num_sum += 8;
        }
        else if (alpa_num == 'T' || alpa_num == 'U' || alpa_num == 'V')
        {
            num_sum += 9;
        }
        else if (alpa_num == 'W' || alpa_num == 'X' || alpa_num == 'Y' || alpa_num == 'Z')
        {
            num_sum += 10;
        }
    }

    cout << num_sum << '\n';
}