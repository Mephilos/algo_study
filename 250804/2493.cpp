// 탑 골드5

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    stack<pair<int,int>> tower;
    
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;

        while (!tower.empty() && tower.top().first < height)
        {
            tower.pop();
        }

        if (tower.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << tower.top().second << " ";
        }
        
        tower.push({height, i});
    }
    cout << '\n';
}
