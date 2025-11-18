#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> name;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        name[temp] = i;
    }
    vector<string> answer;

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;

        if (name.count(temp))
        {
            answer.push_back(temp);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (auto i : answer)
    {
        cout << i << '\n';
    }
}