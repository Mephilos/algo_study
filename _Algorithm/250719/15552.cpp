#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b, over, count = 0;

    cin >> over;

    while (count < over)
    {
        cin >> a >> b;
        cout << a + b << '\n';
        count ++;
    }
}