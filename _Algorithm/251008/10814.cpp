#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, age;
    string name;

    map<int,vector<string>> members;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;
        members[age].push_back(name);
    }

    for (auto [age, names] : members)
    {
        for (auto name: names)
        {
            cout << age << ' ' << name << '\n';
        }
    }
}