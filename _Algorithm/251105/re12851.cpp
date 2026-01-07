#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int myMax = 100000;
vector<int> subin(myMax + 1, -1);
vector<int> subinCnt(myMax + 1);

void BFS(int N)
{
    queue<int> q;
    q.push(N);
    subin[N] = 0;
    subinCnt[N] = 1;
    while (!q.empty())
    {
        int currentPos = q.front();
        q.pop();

        int nPosP = currentPos + 1;
        if (nPosP <= myMax && subin[nPosP] == -1)
        {
            subin[nPosP] = subin[currentPos] + 1;
            subinCnt[nPosP] = subinCnt[currentPos];
            q.push(nPosP);
        }
        else if (nPosP <= myMax && subin[nPosP] == subin[currentPos] + 1)
        {
            subinCnt[nPosP] += subinCnt[currentPos];
        }

        int nPosM = currentPos - 1;
        if (nPosM >= 0 && subin[nPosM] == -1)
        {
            subin[nPosM] = subin[currentPos] + 1;
            subinCnt[nPosM] = subinCnt[currentPos];
            q.push(nPosM);
        }
        else if (nPosM >= 0 && subin[nPosM] == subin[currentPos] + 1)
        {
            subinCnt[nPosM] += subinCnt[currentPos];
        }

        int nPosMT = currentPos * 2;
        if (nPosMT <= myMax && subin[nPosMT] == -1)
        {
            subin[nPosMT] = subin[currentPos] + 1;
            subinCnt[nPosMT] = subinCnt[currentPos];
            q.push(nPosMT);
        }
        else if (nPosMT <= myMax && subin[nPosMT] == subin[currentPos] + 1)
        {
            subinCnt[nPosMT] += subinCnt[currentPos];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    BFS(N);

    cout << subin[K] << '\n';
    cout << subinCnt[K] << '\n';
}