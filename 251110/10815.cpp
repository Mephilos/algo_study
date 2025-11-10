#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> numCard(N);

    for (int i = 0; i < N; i++)
    {
        cin >> numCard[i];
    }
    sort(numCard.begin(), numCard.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {

        int findNum;
        cin >> findNum;
        bool find = false;
        int idxS = 0, idxE = N - 1;
        while (idxS <= idxE)
        {
            int mid = (idxS + idxE) / 2;

            if (numCard[mid] == findNum)
            {
                find = true;
                break;
            }
            else if (numCard[mid] > findNum)
            {
                idxE = mid - 1;
            }
            else
            {
                idxS = mid + 1;
            }
        }

        if (find)
        {
            cout << '1' << '\n';
        }
        else
        {
            cout << '0' << '\n';
        }
    }
}