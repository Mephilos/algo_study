// N과M 1 실3

#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> arr(9);
bool visited[9];

void Sequence(int num1)
{
    if (num1 == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }    
        cout << "\n";

        return;
    }
    
    for (int i = 1; i <= N; i ++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[num1] = i;

            Sequence(num1 + 1);
            
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    Sequence(0);
}