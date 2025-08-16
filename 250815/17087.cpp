#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long S, R;
    cin >> N >> S;
    vector<long long> A(N);
    
    for (int i = 0;i < N; i++)
    {
        cin >> A[i];
        A[i] = abs(A[i] - S);
    }
    
    R = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        R = gcd(R, A[i]);
    }
    cout << R << '\n';
}
