#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MinerSpin(vector<string> &gear, int gearNum)
{
    int temp = gear[gearNum][0];
    for (int k = 0; k < 7; k++)
    {
        gear[gearNum][k] = gear[gearNum][k + 1];
    }
    gear[gearNum][7] = temp;
}

void MajorSpin(vector<string> &gear, int gearNum)
{
    int temp = gear[gearNum][7];
    for (int k = 7; k > 0; k--)
    {
        gear[gearNum][k] = gear[gearNum][k - 1];
    }
    gear[gearNum][0] = temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int score = 0;
    vector<string> gear(4 + 1);

    for (int i = 1; i <= 4; i++)
    {
        cin >> gear[i];
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int spin;
        int gearNum;

        vector<int> spinFlag(4 + 1, 0);
        cin >> gearNum >> spin;

        spinFlag[gearNum] = spin;
        int currentSpin = spin;

        for (int i = gearNum; i < 4; i++)
        {
            if (gear[i][2] != gear[i + 1][6])
            {
                currentSpin = -currentSpin;
                spinFlag[i + 1] = currentSpin;
            }
            else
            {
                break;
            }
        }
        currentSpin = spin;
        for (int i = gearNum; i > 1; i--)
        {
            if (gear[i][6] != gear[i - 1][2])
            {
                currentSpin = -currentSpin;
                spinFlag[i - 1] = currentSpin;
            }
            else
            {
                break;
            }
        }

        for (int j = 1; j <= 4; j++)
        {
            if (spinFlag[j] > 0)
            {
                MajorSpin(gear, j);
            }
            else if (spinFlag[j] < 0)
            {
                MinerSpin(gear, j);
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        if (gear[i][0] == '1')
        {
            score += (1 << (i - 1));
        }
    }
    cout << score << endl;
}
