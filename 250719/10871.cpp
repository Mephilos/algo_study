#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X;
    
    cin >> N >> X;
    
    vector <int> arr = {};
    vector <int> arr2 = {};
    for (int i = 0; i < N; i++)
    {
        int vec_in;
        cin >> vec_in;
        arr.push_back(vec_in);
    }
    for (auto a : arr)
    {
        if (a < X)
        {
            arr2.push_back(a);
        }
    }
    for (auto b : arr2 )
    {
        cout << b << '\n';
    }
}