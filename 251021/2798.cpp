#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> card(N);
    
    int best = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    for (int i = 0; i < N; i ++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = 0;
                sum = card[i] + card[j] + card[k];

                if (best < sum && M >= sum)
                {
                    best = sum;
                }
            }
        }
    }
    cout << best << '\n';
}