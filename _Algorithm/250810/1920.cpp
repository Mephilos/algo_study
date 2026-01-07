#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    vector<int> vec(N);

    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        bool find = false;
        int target;
        cin >> target;

        int start = 0;
        int end = vec.size() - 1;

        while (start <= end)
        {
            int mid_idx = (start + end) / 2;
            int mid_val = vec[mid_idx];

            if (mid_val > target)
            {
                end = mid_idx - 1;
            }
            else if (mid_val < target)
            {
                start = mid_idx + 1;
            }
            else
            {
                find = true;
                break;
            }
        }
        if (find)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}