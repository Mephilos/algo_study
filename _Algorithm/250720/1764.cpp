#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> people;
    
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        people.insert(name);
    }

    vector<string> result;
    
    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        
        if (people.count(name))
        {
            result.push_back(name);
        }
    }
    sort(result.begin(), result.end());
    
    cout << result.size() << '\n';
    for (const auto& name : result)
    {
        cout << name << '\n';
    }

}