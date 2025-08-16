#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string result = "";
    cin >> N;

    if (N == 0)
    {
        cout << "0" << '\n';
        return 0;
    }

    while (N != 0)
    {
        int r = N % -2;
        int q = N / -2;

        if (r < 0)
        {
            r += 2;
            q += 1;
        }
        result = result + to_string(r);

        N = q;
    }
    reverse(result.begin(),result.end());

    cout << result << '\n';
}