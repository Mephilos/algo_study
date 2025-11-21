#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void minerSpin(vector<string> &gears, int gearNum)
{
    int temp;
    temp = gears[gearNum][0];
    for (int i = 0; i < 7; i++)
    {
        gears[gearNum][i] = gears[gearNum][i + 1];
    }
    gears[gearNum][7] = temp;
}
void magerSpin(vector<string> &gears, int gearNum)
{
    int temp;
    temp = gears[gearNum][7];
    for (int i = 7; i > 0; i--)
    {
        gears[gearNum][i] = gears[gearNum][i - 1];
    }
    gears[gearNum][0] = temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> gears(4 + 1);

    for (int i = 1; i <= 4; i++)
    {
        cin >> gears[i];
    }
    int spinNum;
    cin >> spinNum;

    for (int i = 0; i < spinNum; i++)
    {
        int gearNum, spinD;

        cin >> gearNum >> spinD;

        vector<int> spinFlag(4 + 1, 0);

        int curSpin = spinD;
        spinFlag[gearNum] = curSpin;

        for (int i = gearNum; i < 4; i++)
        {
            if (gears[i][2] != gears[i + 1][6])
            {
                curSpin = -curSpin;
                spinFlag[i + 1] = curSpin;
            }
            else
            {
                break;
            }
        }
        curSpin = spinD;
        for (int i = gearNum; i > 1; i--)
        {
            if (gears[i][6] != gears[i - 1][2])
            {
                curSpin = -curSpin;
                spinFlag[i - 1] = curSpin;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= 4; i++)
        {
            if (spinFlag[i] == -1)
            {
                minerSpin(gears, i);
            }
            else if (spinFlag[i] == 1)
            {
                magerSpin(gears, i);
            }
        }
    }
    int sum = 0;

    for (int i = 1; i <= 4; i++)
    {
        if (gears[i][0] == '1')
        {
            sum += 1 << (i - 1);
        }
    }
    cout << sum << '\n';
}