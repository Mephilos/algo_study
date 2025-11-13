#include <iostream>
#include <vector>

using namespace std;

bool isVisitCol[15];
bool isVisitDia1[30];
bool isVisitDia2[30];

int N;
int cnt = 0;
void Solve(int r)
{
    if (r == N)
    {
        cnt++;
        return;
    }

    for (int c = 0; c < N; c++)
    {
        int dia1 = r + c;
        int dia2 = (r - c) + (N - 1);

        if (isVisitCol[c] || isVisitDia1[dia1] || isVisitDia2[dia2])
        {
            continue;
        }

        isVisitCol[c] = true;
        isVisitDia1[dia1] = true;
        isVisitDia2[dia2] = true;

        Solve(r + 1);

        isVisitCol[c] = false;
        isVisitDia1[dia1] = false;
        isVisitDia2[dia2] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    Solve(0);

    cout << cnt << '\n';
}