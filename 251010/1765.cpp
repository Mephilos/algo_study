#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    unordered_set<string> human;

    for (int i = 0; i < N; i++)
    {
        string temp_name;
        cin >> temp_name;
        human.insert(temp_name);
    }

    vector<string> result;

    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;

        if (human.count(name))
        {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (auto name : result)
    {
        cout << name << '\n';
    }
}