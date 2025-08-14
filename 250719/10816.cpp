#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> card(N);
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    sort(card.begin(), card.end());
    
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int targetNum;
        cin >> targetNum;

        auto upper = upper_bound(card.begin(), card.end(), targetNum);
        auto lower = lower_bound(card.begin(), card.end(), targetNum);
        
        cout << upper - lower << '\n';
    }
}


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int N, M;

//     cin >> N;

//     unordered_map<int,int> num_set;
//     for (int i = 0; i < N; i++)
//     {
//         int inputNum;
//         cin >> inputNum;
//         num_set[inputNum]++;
//     }

//     cin >> M;
    
//     for (int i = 0; i < M; i++)
//     {
//         int inputNum2;
//         cin >> inputNum2;
//         cout << num_set[inputNum2] << '\n';
//     }
// }