#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, B;
    cin >> N >> B;
    string result = "";

    while (N > 0)
    {
        int remainder = N % B;
        if (remainder < 10)
        {
            result += (remainder +'0');
        }
        else
        {
            result += (remainder - 10 + 'A');
        }
        N /= B;
    }
    reverse(result.begin(), result.end());

    cout << result << '\n';
}