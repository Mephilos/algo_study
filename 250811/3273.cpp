#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n;
    vector<int> vec(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    cin >> x;
    
    int idx_start = 0, idx_end = n - 1;
    int count = 0;
    while(idx_start < idx_end)
    {
        if (vec[idx_start] + vec[idx_end] == x)
        {
            count++;
            idx_end --;
            idx_start ++;
        }
        else if (vec[idx_start] + vec[idx_end] < x)
        {
            idx_start++;
        }
        else
        {
            idx_end--;
        }
    }
    cout << count << '\n';
}