#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int chillMin = 64;
    int N, M;

    cin >> N >> M;

    vector<string> chess (N);

    for (int i = 0; i < N ; i++)
    {
        cin >> chess[i];
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int startW = 0;
            int startB = 0;
            int currentChillMin = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int r = j; r < j + 8; r++)
                {
                    if ((k + r) % 2 == 0)
                    {
                        if(chess[k][r] == 'B') startW++;
                        if(chess[k][r] == 'W') startB++;
                    }
                    else
                    {
                        if(chess[k][r] == 'B') startB++;
                        if(chess[k][r] == 'W') startW++;
                    }
                }
            }
            currentChillMin = startW > startB ? startB : startW;
            chillMin = currentChillMin > chillMin ? chillMin : currentChillMin;
        }
    }
    cout << chillMin << '\n';
}