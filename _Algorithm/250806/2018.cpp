#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int count = 0;
    int result = 1;
    int start = 1;
    int end = 1;

    while (end <= N )
    {
        if (result == N)
        {
            count++;
            end++;
            if (end > N)
            {
                break;
            }
            result = result + end;
        }
        else if (result < N)
        {
            end++;
            if (end > N)
            {
                break;
            }
            result += end;
        }
        else if (result > N)
        {
            result -= start;
            start++;
        }
    }
    cout << count << '\n';
}
