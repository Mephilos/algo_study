#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N;
    
    vector<int> y(N);

    for (int i =0; i < N; i++)
    {
        cin >> y[i];
    }
    sort(y.begin(),y.end());
    M = y[0] * y[N-1];
    cout << M << '\n';
}