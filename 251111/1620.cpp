#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> nameToNum;
    vector<string> numToName(N + 1);

    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        numToName[i] = temp;
        nameToNum[temp] = i;
    }

    for (int i = 1; i <= M; i++)
    {
        string input;
        cin >> input;

        if (input[0] >= '0' && input[0] <= '9')
        {
            int temp = stoi(input);
            cout << numToName[temp] << '\n';
        }
        else
        {
            cout << nameToNum[input] << '\n';
        }
    }
}
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N >> M;

//     unordered_map<string, int> nameToNum;
//     vector<string> numToName(N + 1);

//     for (int i = 1; i <= N; i++)
//     {
//         string temp;
//         cin >> temp;
//         numToName[i] = temp;
//         nameToNum[temp] = i;
//     }

//     for (int i = 1; i <= M; i++)
//     {
//         string input;
//         cin >> input;

//         try
//         {
//             int num = stoi(input);
//             cout << numToName[num] << '\n';
//         }
//         catch (const std::invalid_argument &e)
//         {
//             cout << nameToNum[input] << '\n';
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N >> M;

//     unordered_map<string, int> nameToNum;
//     vector<string> numToName(N + 1);

//     for (int i = 1; i <= N; i++)
//     {
//         string pokeName;
//         cin >> pokeName;

//         numToName[i] = pokeName;
//         nameToNum[pokeName] = i;
//     }

//     for (int i = 0; i < M; i++)
//     {
//         string question;
//         cin >> question;

//         if (isdigit(question[0]))
//         {
//             int temp = stoi(question);
//             cout << numToName[temp] << '\n';
//         }
//         else
//         {
//             cout << nameToNum[question] << '\n';
//         }
//     }
// }