#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    unordered_set<int> numCard(N);

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numCard.insert(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {

        int findNum;
        cin >> findNum;
        cout << numCard.count(findNum) << '\n';
    }
}