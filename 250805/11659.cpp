#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> sum(N+1);
    
    for (int i = 1; i <= N ; i++)
    {
        int temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    
    for (int i = 1; i <= M ; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << '\n'; 
    }
}