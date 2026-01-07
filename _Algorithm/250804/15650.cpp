#include <iostream>
#include <vector>

using namespace std;
int N,M;
vector<int> vec(9);


void func(int num, int num2)
{
    if (num == M)
    {
        for (int i = 0;i < M; i++)
        {
            cout << vec[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = num2; i <= N; i++)
    {
        vec[num] = i;
        func(num + 1, i +1 );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    func(0, 1);
}