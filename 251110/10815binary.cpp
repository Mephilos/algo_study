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
        cout << binary_search(numCard.begin(), numCard.end(), findNum) << '\n';
    }
}