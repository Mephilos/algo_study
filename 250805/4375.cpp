#include <iostream>

using namespace std;

int main()
{
    int T;

    while(cin>>T)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long num = 1;
        int count = 1;
        while(true)
        {
            if (num % T == 0)
            {
                break;
            }
            num = (num * 10 + 1) % T;
            count ++;
        }
        cout << count << '\n';
    }
}