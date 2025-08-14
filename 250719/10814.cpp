#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int age, N;
    string name;
    map<int, vector<string>> members;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;
        members[age].push_back(name);
    }
    for (auto const& [age, names] : members)
    {
        for (auto const& name : names)
        {
            cout << age << ' ' << name << '\n';
        }
    }
}