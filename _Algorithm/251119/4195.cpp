#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;
vector<int> parent;
vector<int> setSize;

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

int uniSet(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return setSize[v];

    if (setSize[u] > setSize[v])
        swap(u, v);
    parent[u] = v;

    setSize[v] += setSize[u];

    return setSize[v];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        int F;
        cin >> F;
        parent.clear();
        setSize.clear();
        parent.resize(F * 2 + 1);
        setSize.resize(F * 2 + 1, 1);

        iota(parent.begin(), parent.end(), 0);

        unordered_map<string, int> fList;
        int listCnt = 1;

        for (int i = 0; i < F; i++)
        {
            string temp, temp2;
            cin >> temp >> temp2;
            if (fList.find(temp) == fList.end())
            {
                fList[temp] = listCnt++;
            }

            if (fList.find(temp2) == fList.end())
            {
                fList[temp2] = listCnt++;
            }

            int u = fList[temp];
            int v = fList[temp2];

            cout << uniSet(u, v) << '\n';
        }
    }
}