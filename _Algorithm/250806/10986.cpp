#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; 
    long long count = 0;
    cin >> N >> M;
    vector<long long> num(N + 1);
    vector<long long> remainVec(M, 0);

    for (int i = 1; i <= N; i++)
    {
        int tempNum;
        cin >> tempNum;

        num[i] = (num[i - 1] + tempNum) % M;
        remainVec[num[i]]++;
    }
    count += remainVec[0];
    for (int i = 0; i < M; i++)
    {
        count += remainVec[i] * (remainVec[i]- 1) / 2;
    }
    
    cout << count << '\n';
}