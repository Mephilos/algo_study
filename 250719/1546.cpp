// #include <iostream>

// using namespace std;

// int main()
// {
//     int N, max = 0;
//     float result = 0;
//     cin >> N;
    
//     int* arr = new int[N];

//     for (int i = 0; i < N; i++)
//     {
//         cin >> arr[i];
        
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     // cout << max << endl;
//     for (int i = 0; i < N; i++)
//     {
//         // cout << arr[i] << endl;
//         result += static_cast<float>(arr[i])/max * 100;
//         // cout << result << endl;
//     }
//     cout << fixed;
//     cout << result/N << endl;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<double> score(N);

    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
    }

    double maxScore = *max_element(score.begin(),score.end());
    double sum = accumulate(score.begin(), score.end(), 0);

    double average = (sum/maxScore * 100) / N;
    cout << fixed;
    cout.precision(6);

    cout << average << '\n';
}