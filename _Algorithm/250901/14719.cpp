#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int total_water = 0;
    int H, W;
    cin >> H >> W;
    vector<int> block (W);

    for (int i = 0 ; i < W ; i++)
    {
        cin >> block[i];
    }
    for (int i = 0 ; i < W ; i++)
    {
        int left_max = 0;
        for (int j = 0; j < i; j++)
        {
            left_max = max(left_max, block[j]);
        }
        int right_max = 0;
        for (int j = i + 1; j < W; j++)
        {
            right_max = max(right_max, block[j]);
        }
        int water_level = min(left_max, right_max);
        if (water_level > block[i])
        {
            total_water += water_level - block[i];
        }
    }
    cout << total_water << '\n';
}