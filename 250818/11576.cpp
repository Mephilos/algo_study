#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A, B, N;
    cin >> A >> B;
    cin >> N;
    
    long long decimal = 0;
    for (int i = 0; i < N; i++)
    {
        int digit;
        cin >> digit;
        decimal = decimal * A + digit;
    }
    
    vector<int> num2;
    while (decimal > 0)
    {
        num2.push_back(decimal % B);
        decimal /= B;
    }
    
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        cout << num2[i] << ' ';
    }
}