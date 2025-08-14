#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> qN;
    
    int N;
    cin >> N;
    for (int i = 1; i <= N ; i++)
    {
        qN.push(i);
    }

    while (qN.size()>1)
    {
        qN.pop();
        qN.push(qN.front());
        qN.pop();
    }
    cout << qN.front() << '\n';
}