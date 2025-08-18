#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec(9);
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - vec[i] - vec[j] == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << vec[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }
}