// #include <unordered_map>
// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N;

//     unordered_map<int, int> numSet;

//     for (int i = 0; i < N; i++)
//     {
//         int temp;
//         cin >> temp;
//         numSet[temp]++;
//     }

//     cin >> M;

//     for (int i = 0; i < M; i++)
//     {
//         int temp;
//         cin >> temp;
//         cout << numSet[temp] << ' ';
//     }
//     cout << '\n';
// }
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> numSet(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numSet[i];
    }

    sort(numSet.begin(), numSet.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        auto lo = lower_bound(numSet.begin(), numSet.end(), temp);
        auto hi = upper_bound(numSet.begin(), numSet.end(), temp);

        int answer = hi - lo;

        cout << answer << ' ';
    }
    cout << '\n';
}