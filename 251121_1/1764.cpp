#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> man;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        man[str] = i;
    }
    vector<string> answer;
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if (man.find(str) != man.end())
        {
            answer.push_back(str);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (string i : answer)
    {
        cout << i << '\n';
    }
}