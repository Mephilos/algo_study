// N goa M S3

#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> vec(8);

void func(int num1)
{
    if (num1 == M)
    {
        for (int i = 0;i < M; i++)
        {
            cout << vec[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        vec[num1] = i;
        func(num1+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    func(0);
}