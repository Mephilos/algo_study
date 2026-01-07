#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
using Node = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    
    deque<Node> depWindow;
    
    for (int i = 0; i < N; i++)
    {
        int minInput;
        cin >> minInput;

        while (depWindow.size() && depWindow.back().first > minInput)
        {
            depWindow.pop_back();
        }
        depWindow.push_back(Node(minInput, i));
        if (depWindow.front().second <= i - L)
        {
            depWindow.pop_front();
        }
        cout << depWindow.front().first << ' ';
    }
    cout << '\n';
}