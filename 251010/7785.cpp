#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    set<string, greater<string>> worker;

    for (int i = 0; i < n ; i++)
    {
        string temp_inoutput;
        string name;
        
        cin >> name >> temp_inoutput;
        
        if (temp_inoutput == "leave")
        {
            worker.erase(name);
        }
        else
        {
            worker.insert(name);
        }
    }

    for (const auto& name : worker)
    {
        cout << name << '\n';
    }
}