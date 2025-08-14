#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> vecNum(N);

    for (int i = 0; i < vecNum.size(); i++)
    {
        cin >> vecNum[i];
    }
    sort(vecNum.begin(), vecNum.end());

    for (const auto& a : vecNum)
    {
        cout << a << '\n';
    }
}