#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cmath>

using namespace std;

vector<int> path;
vector<pair<int, int>> house;
vector<pair<int, int>> chic;

int N, M;
int answer = INT_MAX;

void solve(int cnt, int start)
{
    int currentMin = 0;
    if (cnt == M)
    {
        for (int i = 0; i < house.size(); i++)
        {
            int houseChicDist = INT_MAX;

            for (int cIdx : path)
            {
                int dist = abs(chic[cIdx].first - house[i].first) + abs(chic[cIdx].second - house[i].second);

                houseChicDist = min(houseChicDist, dist);
            }
            currentMin += houseChicDist;
        }
        answer = min(answer, currentMin);
        return;
    }

    for (int i = start; i < chic.size(); i++)
    {
        path.push_back(i);

        solve(cnt + 1, i + 1);

        path.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 2)
                chic.push_back({i, j});
            if (temp == 1)
                house.push_back({i, j});
        }
    }
    solve(0, 0);

    cout << answer << '\n';
}