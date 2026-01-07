#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cScale;

    getline(cin, cScale);

    if (cScale == "1 2 3 4 5 6 7 8")
    {
        cout << "ascending" << '\n';
    }
    else if (cScale == "8 7 6 5 4 3 2 1")
    {
        cout << "descending" << '\n';
    }
    else
    {
        cout << "mixed" << '\n';
    }
}