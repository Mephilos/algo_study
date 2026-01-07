#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;   
    vector<int> numSet(N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> numSet[i]; 
    }

    sort(numSet.begin(), numSet.end());

    for (int i = 0; i < N; i++)
    {
        int find = numSet[i];
        int idx_start = 0;
        int idx_end = N - 1;

        while (idx_start < idx_end)
        {
            if (numSet[idx_start] + numSet[idx_end] == find)
            {
                if (i != idx_start && i != idx_end)
                {
                    count++;
                    break;
                }
                else if (i == idx_start)
                {
                    idx_start++;
                }
                else
                {
                    idx_end--;
                }
            }
            else if (numSet[idx_start] + numSet[idx_end] < find)
            {
                idx_start++;
            }
            else 
            {
                idx_end--;
            }
        }
    }
    cout << count << '\n';
}