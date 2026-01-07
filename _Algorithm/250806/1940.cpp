#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;
    vector<int> parts(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> parts[i];
    }

    int start = 0;
    int end = N - 1;
    int count = 0;
    
    sort(parts.begin(), parts.end());

    while (start < end)
    {   
        int assemble = parts[start] + parts[end];
        if (assemble == M)
        {
            count++;
            end--;
            start++;
        }
        else if (assemble < M)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << count << '\n';
}