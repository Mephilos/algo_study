#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> origin(N);

    for (int i = 0; i < N; i++)
    {
        cin >> origin[i];
    }

    vector<int> temp = origin;

    sort(temp.begin(), temp.end());

    auto it = unique(temp.begin(), temp.end());

    temp.erase(it, temp.end());

    unordered_map<int, int> map;
    for (int i = 0; i < temp.size(); i++)
    {
        map[temp[i]] = i;
    }

    for (int i : origin)
    {
        cout << map[i] << ' ';
    }
    cout << '\n';
}
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int N;
//     cin >> N;

//     vector<int> origin(N);

//     for (int i = 0; i < N; i++)
//     {
//         cin >> origin[i];
//     }

//     vector<int> temp = origin;

//     sort(temp.begin(), temp.end());

//     auto it = unique(temp.begin(), temp.end());

//     temp.erase(it, temp.end());

//     for (int i : origin)
//     {
//         auto it = lower_bound(temp.begin(), temp.end(), i);

//         int num2 = it - temp.begin();

//         cout << num2 << ' ';
//     }
//      cout << '\n';
// }