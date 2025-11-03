#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int gameScore = 0;

    vector<string> gear(4 + 1);

    for (int i = 1; i <= 4; i++)
    {
        cin >> gear[i];
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        vector<int> spinFlag(4 + 1, 0);
        int spin;
        int num;
        cin >> num >> spin;

        int currentSpin = spin;
        spinFlag[num] = currentSpin;

        for (int j = num; j < 4; j++)
        {
            if (gear[j][2] != gear[j + 1][6])
            {
                currentSpin = -currentSpin;
                spinFlag[j + 1] = currentSpin;
            }
            else
            {
                break;
            }
        }
        currentSpin = spin;
        for (int j = num; j > 1; j--)
        {
            if (gear[j][6] != gear[j - 1][2])
            {
                currentSpin = -currentSpin;
                spinFlag[j - 1] = currentSpin;
            }
            else
            {
                break;
            }
        }

        for (int j = 1; j <= 4; j++)
        {
            if (spinFlag[j] < 0)
            {
                int temp = gear[j][0];
                for (int k = 0; k < 7; k++)
                {
                    gear[j][k] = gear[j][k + 1];
                }
                gear[j][7] = temp;
            }

            if (spinFlag[j] > 0)
            {
                int temp = gear[j][7];
                for (int k = 7; k > 0; k--)
                {
                    gear[j][k] = gear[j][k - 1];
                }
                gear[j][0] = temp;
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        if (gear[i][0] == '1')
        {
            gameScore += (1 << (i - 1));
        }
    }
    cout << gameScore << '\n';
}