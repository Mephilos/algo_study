#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N;

    unordered_set<int> num_set;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        num_set.insert(num);
    }

    cin >> M;
    
    for (int i = 0; i < M; i++)
    {
        int taget;
        cin >> taget;
        if (num_set.count(taget))
        {
            cout << 1 << '\n';
        }else
        {
            cout << 0 << '\n';
        }
    }   
}