#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int checkBingo(const vector<vector<bool>>& check)
{
    int bingo_count = 0;

    for (int i = 0; i < 5; i++)
    {
        bool is_bingo = true;
        for (int j = 0; j < 5; j++)
        {
            if (!check[i][j])
            {
                is_bingo = false;
                break;
            }
        }
        if (is_bingo)
        {
            bingo_count++;
        }
    }

    for (int j = 0; j < 5; j++)
    {
        bool is_bingo = true;
        for (int i = 0; i < 5; i++)
        {
            if(!check[i][j])
            {
                is_bingo = false;
                break;
            }
        }
        if (is_bingo)
        {
            bingo_count++;
        }
    }
    bool is_bingo1 = true;
    for (int i = 0; i < 5; i++)
    {
        if (!check[i][i])
        {
            is_bingo1 = false;
            break;
        }
    }
    if (is_bingo1)
    {
        bingo_count ++;
    }
    
    bool is_bingo2 = true;
    for (int i = 0; i < 5 ; i++)
    {
        if (!check[i][4 - i])
        {
            is_bingo2 = false;
            break;
        }
    }
    if (is_bingo2)
    {
        bingo_count++;
    }
    return bingo_count;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int,int>> position(26);
    
    vector<vector<bool>> check(5, vector<bool>(5,false));
    int bingo_count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            position[num] = {i, j};
        }
    }
    for (int k = 1; k <= 25; k++)
    {
        int temp;
        cin >> temp;

        pair<int, int> pos = position[temp];
        int row = pos.first;
        int col = pos.second;

        check[row][col] = true;

        int bingo = checkBingo(check);

        if (bingo >= 3)
        {
            cout << k << '\n';
            return 0;
        }
    }
}