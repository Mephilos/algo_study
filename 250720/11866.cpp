#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    queue<int> num;
    
    for (int i = 1; i < N + 1; i++)
    {
        num.push(i);
    }

    cout << "<";
    
    while(!num.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            num.push(num.front());
            num.pop();
        }
        
        cout << num.front();
        num.pop();

        if(!num.empty())
        {
            cout << ", ";
        }
    }
    cout << ">" << '\n';
}