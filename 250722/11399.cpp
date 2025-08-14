#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, result = 0, temp = 0;
    
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    
    sort (P.begin(), P.end());

    for (int i = 0; i < N; i++)
    {
        temp += P[i];
        result += temp;
    }

    cout << result << '\n';
}