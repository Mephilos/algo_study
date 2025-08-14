#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N;
//     cin >> N;

//     vector<pair<int, int>> coords(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> coords[i].first >> coords[i].second;
//     }

//     sort(coords.begin(), coords.end());

//     for (auto& a : coords)
//     {
//         cout << a.first << ' ' << a.second << '\n';
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num1, num2;
    map<int, vector<int>> coords;
    
    for (int i = 0; i < N; i++)
    {
        cin >> num1 >> num2;
        coords[num1].push_back(num2);
    }
    for (auto& pair : coords)
    {
        sort(pair.second.begin(), pair.second.end());
    }
    for (auto const& [num1, num2] : coords)
    {
        for (auto const& num : num2)
        {
            cout << num1 << ' ' << num << '\n';
        }
    }
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N;
//     cin >> N;
    
//     vector<vector<int>> coords(N, vector<int>(2));

//     for (int i = 0; i < N; i ++)
//     {
//         cin >> coords[i][0] >> coords[i][1];
//     }

//     sort(coords.begin(),coords.end());

//     for (const auto& point : coords)
//     {
//         cout << point[0] << ' ' << point[1] << '\n';
//     }
// }