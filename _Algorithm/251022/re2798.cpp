#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M,  maxSum = 0;
    
    cin >> N >> M;
    vector<int> card(N, 0);
    for (int i = 0; i < N ; i++)
    {
        cin >> card[i];
    }

    for (int i = 0; i < card.size(); i++)
    {
        for (int j = i + 1; j < card.size(); j++)
        {
            for (int k = j + 1; k < card.size(); k++)
            {
                int cardSum = 0;
                cardSum = card[i] + card[j] + card[k];
                
                if (cardSum <= M && maxSum < cardSum)
                {
                    maxSum = cardSum;    
                }
            }
        }
    }
    cout << maxSum << '\n';
}