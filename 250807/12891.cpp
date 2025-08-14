#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    
}









// bool isValid(const vector<int>& windowConunts, const vector<int>& strCounts)
// {
//     if (windowConunts[0] >= strCounts[0] &&
//         windowConunts[1] >= strCounts[1] &&
//         windowConunts[2] >= strCounts[2] &&
//         windowConunts[3] >= strCounts[3])
//         {
//             return true;
//         }
//         return false;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int S, P;
//     cin >> S >> P;
//     string dnaStr;
//     cin >> dnaStr;

//     vector<int> strCounts(4);
//     for (int i = 0; i < 4; i++)
//     {
//         cin >> strCounts[i];
//     }

//     vector<int> windowCounts(4, 0);
//     int answer = 0;

//     for (int i = 0; i < P; i++)
//     {
//         if (dnaStr[i] == 'A') windowCounts[0]++;
//         else if (dnaStr[i] == 'C') windowCounts[1]++;
//         else if (dnaStr[i] == 'G') windowCounts[2]++;
//         else if (dnaStr[i] == 'T') windowCounts[3]++;
//     }

//     if (isValid(windowCounts, strCounts))
//     {
//         answer++;
//     }

//     for (int i = P; i < S; i++)
//     {
//         if (dnaStr[i] == 'A') windowCounts[0]++;
//         else if (dnaStr[i] == 'C') windowCounts[1]++;
//         else if (dnaStr[i] == 'G') windowCounts[2]++;
//         else if (dnaStr[i] == 'T') windowCounts[3]++;

//         char removeChar = dnaStr[i - P];
//         if (removeChar == 'A') windowCounts[0]--;
//         else if (removeChar == 'C') windowCounts[1]--;
//         else if (removeChar == 'G') windowCounts[2]--;
//         else if (removeChar == 'T') windowCounts[3]--;

//         if (isValid(windowCounts, strCounts))
//         {
//             answer++;
//         }
//     }
//     cout << answer << '\n';
// }