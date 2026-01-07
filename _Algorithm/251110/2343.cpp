#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> lesson(N);
    for (int i = 0; i < N; i++)
    {
        cin >> lesson[i];
    }

    int low = *max_element(lesson.begin(), lesson.end());
    int high = accumulate(lesson.begin(), lesson.end(), 0);

    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = 0;
        int cnt = 1;
        for (int l : lesson)
        {
            if (sum + l > mid)
            {
                cnt++;
                sum = l;
            }
            else
                sum += l;
        }
        if (M >= cnt)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << result << '\n';
}