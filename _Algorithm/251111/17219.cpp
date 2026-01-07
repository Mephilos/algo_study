#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> pwSave;

    for (int i = 0; i < N; i++)
    {
        string temp, pw;
        cin >> temp >> pw;
        pwSave[temp] = pw;
    }

    for (int i = 0; i < M; i++)
    {
        string find;
        cin >> find;

        cout << pwSave[find] << '\n';
    }
}